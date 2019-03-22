/*
    Copyright (c) 2018 Xavier Leclercq

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

#include "EmbeddedTreeDB.h"
#include "EmbeddedTreeDBImpl.h"

namespace DiplodocusDB
{

EmbeddedTreeDB::EmbeddedTreeDB()
    : m_impl(std::make_shared<EmbeddedTreeDBImpl>())
{
}

EmbeddedTreeDB::~EmbeddedTreeDB()
{
}

void EmbeddedTreeDB::create(const boost::filesystem::path& path,
                            Ishiko::Error& error)
{
    m_impl->create(path, error);
}

void EmbeddedTreeDB::open(const boost::filesystem::path& path,
                          Ishiko::Error& error)
{
    m_impl->open(path, error);
}

void EmbeddedTreeDB::close()
{
    m_impl->close();
}

TreeDBNode& EmbeddedTreeDB::root()
{
    return m_impl->root();
}

TreeDBNode EmbeddedTreeDB::insert(TreeDBNode& parent, size_t index, const TreeDBKey& key, Ishiko::Error& error)
{
    return m_impl->insert(parent, index, key, error);
}

TreeDBNode EmbeddedTreeDB::insertBefore(TreeDBNode& parent, TreeDBNode& child, const TreeDBKey& key,
    Ishiko::Error& error)
{
    return m_impl->insertBefore(parent, child, key, error);
}

TreeDBNode EmbeddedTreeDB::insertAfter(TreeDBNode& parent, TreeDBNode& child, const TreeDBKey& key,
    Ishiko::Error& error)
{
    return m_impl->insertAfter(parent, child, key, error);
}

TreeDBNode EmbeddedTreeDB::append(TreeDBNode& parent, const TreeDBKey& key, Ishiko::Error& error)
{
    return m_impl->append(parent, key, error);
}

void EmbeddedTreeDB::commitNode(TreeDBNode& node, Ishiko::Error& error)
{
    m_impl->commitNode(static_cast<EmbeddedTreeDBNodeImpl&>(*node.impl()), error);
}

}
