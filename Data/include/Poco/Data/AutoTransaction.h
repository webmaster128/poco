//
// AutoTransaction.h
//
// $Id: //poco/Main/Data/include/Poco/Data/AutoTransaction.h#2 $
//
// Library: Data
// Package: Core
// Module:  AutoTransaction
//
// Definition of the AutoTransaction class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//



#ifndef Data_AutoTransaction_INCLUDED
#define Data_AutoTransaction_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/Data/Session.h"
#include "Poco/Logger.h"


namespace Poco {
namespace Data {


class Data_API AutoTransaction
	/// AutoTransaction helps with transactions in domain logic.
	/// When an AutoTransaction object is created, it first checks whether a
	/// transaction is in progress. If not, a new transaction is created.
	/// When the AutoTransaction is destroyed, and commit() has been called,
	/// nothing is done. Otherwise, the current transaction is rolled back.
{
public:
	AutoTransaction(Poco::Data::Session& session, Poco::Logger* pLogger = 0);
		/// Creates the AutoTransaction, using the given database session and logger.
		
	~AutoTransaction();
		/// Destroys the AutoTransaction.
		/// Rolls back the current database transaction if it has not been commited
		/// (by calling commit()), or rolled back (by calling rollback()).
		///
		/// If an exception is thrown during rollback, the exception is logged
		/// and no further action is taken. 
		
	void commit();
		/// Commits the current transaction.
		
	void rollback();
		/// Rolls back the current transaction.
		
private:
	AutoTransaction();
	AutoTransaction(const AutoTransaction&);
	AutoTransaction& operator = (const AutoTransaction&);
	
	Session& _session;
	Logger*  _pLogger;
	bool     _mustRollback;
};


} } // namespace Poco::Data


#endif // Data_AutoTransaction_INCLUDED