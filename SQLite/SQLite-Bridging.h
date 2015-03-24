//
// SQLite.swift
// https://github.com/stephencelis/SQLite.swift
// Copyright (c) 2014-2015 Stephen Celis.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

@import sqlite3;
@import Foundation;

typedef int (^SQLiteBusyHandlerCallback)(int times);
int SQLiteBusyHandler(sqlite3 * handle, SQLiteBusyHandlerCallback callback);

typedef void (^SQLiteTraceCallback)(const char * SQL);
void SQLiteTrace(sqlite3 * handle, SQLiteTraceCallback callback);

typedef void (^SQLiteUpdateHookCallback)(int operation, const char * db, const char * table, sqlite3_int64 rowid);
void SQLiteUpdateHook(sqlite3 * handle, SQLiteUpdateHookCallback callback);

typedef int (^SQLiteCommitHookCallback)();
void SQLiteCommitHook(sqlite3 * handle, SQLiteCommitHookCallback callback);

typedef void (^SQLiteRollbackHookCallback)();
void SQLiteRollbackHook(sqlite3 * handle, SQLiteRollbackHookCallback callback);

typedef void (^SQLiteCreateFunctionCallback)(sqlite3_context * context, int argc, sqlite3_value ** argv);
int SQLiteCreateFunction(sqlite3 * handle, const char * name, int argc, int deterministic, SQLiteCreateFunctionCallback callback);

typedef int (^SQLiteCreateCollationCallback)(const char * lhs, const char * rhs);
int SQLiteCreateCollation(sqlite3 * handle, const char * name, SQLiteCreateCollationCallback callback);

typedef NSString * (^SQLiteTokenizerNextCallback)(const char * input, int * inputOffset, int * inputLength);
int SQLiteRegisterTokenizer(sqlite3 * db, const char * module, const char * tokenizer, SQLiteTokenizerNextCallback callback);
