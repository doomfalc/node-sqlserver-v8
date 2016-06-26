#include "stdafx.h"
#include "OdbcConnection.h"
#include "OdbcStatementCache.h"
#include "FreeStatementOperation.h"

namespace mssql
{
	bool FreeStatementOperation::TryInvokeOdbc()
	{
		connection->statements->checkin(statementId);
		//fprintf(stderr, " checkin statementId %d size %llu\n", statementId, connection->statements->size());
		return true;
	}

	Local<Value> FreeStatementOperation::CreateCompletionArg()
	{
		nodeTypeFactory fact;
		return fact.null();
	}
}