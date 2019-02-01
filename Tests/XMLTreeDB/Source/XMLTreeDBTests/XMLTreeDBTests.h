/*
    Copyright (c) 2019 Xavier Leclercq

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

#ifndef _DIPLODOCUSDB_TEST_TREEDB_XMLTREEDBTESTS_XMLTREEDBTESTS_H_
#define _DIPLODOCUSDB_TEST_TREEDB_XMLTREEDBTESTS_XMLTREEDBTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class XMLTreeDBTests
{
public:
    static void AddTests(Ishiko::TestFramework::TestHarness& theTestHarness);

private:
    static Ishiko::TestFramework::TestResult::EOutcome CreationTest1();
    static Ishiko::TestFramework::TestResult::EOutcome CreateTest1(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome OpenTest1(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome OpenTest2(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome OpenTest3(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome OpenTest4(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome OpenTest5(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome ParentTest1(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome ParentTest2(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome ChildrenTest1(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome ChildrenTest2(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome NextSiblingTest1(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome NextSiblingTest2(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome NextSiblingTest3(Ishiko::TestFramework::Test& test);
    static Ishiko::TestFramework::TestResult::EOutcome InsertTest1(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome AppendTest1(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome AppendTest2(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome AppendTest3(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome AppendTest4(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome AppendTest5(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome AppendTest6(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome SetTest1(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome SetTest2(Ishiko::TestFramework::FileComparisonTest& test);
    static Ishiko::TestFramework::TestResult::EOutcome RemoveAllTest1(Ishiko::TestFramework::FileComparisonTest& test);
};

#endif

