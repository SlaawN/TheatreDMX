//---------------------------------------------------------------------------

#pragma hdrstop

#include "MySQL.h"
#define HOST"192.168.64.67"
#define USER"dmx"
#define PASSWORD"dmx"
#define DATABASE"THEATRE_DMX"
#include <sstream>


//---------------------------------------------------------------------------

MySQL::MySQL(TMemo* Memo)
{
  this->Memo1=Memo;
}
bool MySQL::Connexion()
{

//	mySQL = mysql_init(NULL);
//	//mySQL, "192.168.64.67", "dmx", "dmx", "THEATRE_DMX"
//	conn=mysql_real_connect(mySQL, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0);
//	if(conn==NULL)
//	{
//		return false;
//	}
//	else
//	{
	   return true;
	//}

}
bool MySQL::update(String req)
{


}
bool MySQL::insert(String req)
{

}
bool MySQL::supp(String req)
{


}
bool MySQL::select(AnsiString req)
{

//		AnsiString select = "SELECT `Nom` FROM `Course`";
//		if (!mysql_query(mySQL, select.c_str()))
//		{
//			myRES = mysql_store_result(mySQL);
//			if (myRES)
//			{
//				for(unsigned int i = 0; i < myRES->row_count; i++)
//				{
//					myROW = mysql_fetch_row(myRES);
//					for(unsigned int j = 0; j < mysql_num_fields(myRES); j++)
//					{
//						AnsiString aStr = myROW[j];
						this->Memo1->Lines->Add("2");
//					}
//				}
//				mysql_free_result(myRES);
//			}
//		}
}

#pragma package(smart_init)
