/*
    Copyright (c) 2018-2019 Xavier Leclercq

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

#include "NodeIDTests.h"
#include "NodeIDAllocatorTests.h"
#include "RecordTests.h"
#include "SiblingNodesRecordGroupTests.h"
#include "SiblingNodesRecordGroupCacheTests.h"
#include "MasterFileTests.h"
#include "SecondaryFileTests.h"
#include "RecordFilesSetTests.h"
#include "CachedRecordFilesSetTests.h"
#include "EmbeddedTreeDBTests.h"
#include "TransactionTests.h"
#include "Ishiko/TestFramework/TestFrameworkCore.h"
#include <boost/filesystem/operations.hpp>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("DiplodocusEmbeddedTreeDB");

    theTestHarness.environment().setTestDataDirectory("../../TestData");
    theTestHarness.environment().setTestOutputDirectory("../../TestOutput");
    boost::filesystem::create_directories("../../TestOutput");
    theTestHarness.environment().setReferenceDataDirectory("../../ReferenceData");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<NodeIDTests>();
    theTests.append<NodeIDAllocatorTests>();
    theTests.append<RecordTests>();
    theTests.append<SiblingNodesRecordGroupTests>();
    theTests.append<SiblingNodesRecordGroupCacheTests>();
    theTests.append<MasterFileTests>();
    theTests.append<SecondaryFileTests>();
    theTests.append<RecordFilesSetTests>();
    theTests.append<CachedRecordFilesSetTests>();
    theTests.append<EmbeddedTreeDBTests>();
    theTests.append<TransactionTests>();

    return theTestHarness.run();
}
