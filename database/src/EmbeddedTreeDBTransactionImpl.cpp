/*
    Copyright (c) 2019-2022 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "EmbeddedTreeDBTransactionImpl.h"
#include "EmbeddedDocumentDBNodeImpl.hpp"

using namespace DiplodocusDB;

TreeDBNode EmbeddedTreeDBTransactionImpl::appendChildNode(EDDBImpl::StorageEngine& storageEngine, TreeDBNode& parent,
    const std::string& name, const Value& value, Ishiko::Error& error)
{
    TreeDBNode result;

    EmbeddedDocumentDBNodeImpl& parentNodeImpl = static_cast<EmbeddedDocumentDBNodeImpl&>(*parent.impl());
    result = TreeDBNode(
        std::make_shared<EmbeddedDocumentDBNodeImpl>(parentNodeImpl.nodeID(), EDDBImpl::NodeID(0), name));
    EmbeddedDocumentDBNodeImpl& nodeImpl = static_cast<EmbeddedDocumentDBNodeImpl&>(*result.impl());
    nodeImpl.value() = value;

    std::shared_ptr<EDDBImpl::SiblingNodesRecordGroup> existingSiblingNodesRecordGroup;
    EFindResult findResult = findSiblingNodesRecordGroup(storageEngine, parentNodeImpl.nodeID(),
        existingSiblingNodesRecordGroup, error);
    if (!error)
    {
        if (findResult != eNotFound)
        {
            existingSiblingNodesRecordGroup->push_back(
                EDDBImpl::SiblingNodeRecordGroup(nodeImpl.name(), nodeImpl.value(), nodeImpl.nodeID()));
            if (findResult == eFoundInCache)
            {
                m_updatedSiblingNodesRecordGroups.push_back(existingSiblingNodesRecordGroup);
            }
        }
        else
        {
            m_newSiblingNodesRecordGroups.emplace_back(
                std::make_shared<EDDBImpl::SiblingNodesRecordGroup>(nodeImpl.parentNodeID(),
                    EDDBImpl::SiblingNodeRecordGroup(nodeImpl.name(), nodeImpl.value(), nodeImpl.nodeID())));
        }
    }

    return result;
}

void EmbeddedTreeDBTransactionImpl::commit(EDDBImpl::StorageEngine& storageEngine, Ishiko::Error& error)
{
    for (std::shared_ptr<EDDBImpl::SiblingNodesRecordGroup>& siblingNodes : m_updatedSiblingNodesRecordGroups)
    {
        storageEngine.updateSiblingNodesRecordGroup(*siblingNodes, error);
        if (error)
        {
            break;
        }
    }
    for (std::shared_ptr<EDDBImpl::SiblingNodesRecordGroup>& siblingNodes : m_newSiblingNodesRecordGroups)
    {
        storageEngine.addSiblingNodesRecordGroup(*siblingNodes, error);
        if (error)
        {
            break;
        }
    }
}

void EmbeddedTreeDBTransactionImpl::rollback()
{
    // TODO : need to clear the m_new and m_updated and unlock the nodes, need to also lock the nodes too in the first
    // place
}

EmbeddedTreeDBTransactionImpl::EFindResult EmbeddedTreeDBTransactionImpl::findSiblingNodesRecordGroup(
    EDDBImpl::StorageEngine& storageEngine, const EDDBImpl::NodeID& parentNodeID,
    std::shared_ptr<EDDBImpl::SiblingNodesRecordGroup>& siblingNodes, Ishiko::Error& error)
{
    for (std::shared_ptr<EDDBImpl::SiblingNodesRecordGroup>& group : m_newSiblingNodesRecordGroups)
    {
        if (group->parentNodeID() == parentNodeID)
        {
            siblingNodes = group;
            return eFoundInNew;
        }
    }
    for (std::shared_ptr<EDDBImpl::SiblingNodesRecordGroup>& group : m_updatedSiblingNodesRecordGroups)
    {
        if (group->parentNodeID() == parentNodeID)
        {
            siblingNodes = group;
            return eFoundInUpdated;
        }
    }
    bool found = storageEngine.findSiblingNodesRecordGroup(parentNodeID, siblingNodes, error);
    if (found)
    {
        return eFoundInCache;
    }
    else
    {
        return eNotFound;
    }
}
