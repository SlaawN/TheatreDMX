﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include "PilotageLumiere.h"
#include "Unit1.h"
#include <string.h>
#include <deque>

#include <vector>
#include <sstream>
#define __WIN__
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
DWORD WINAPI TForm1::RecvThread(LPVOID params)
{
	TForm1 * form = (TForm1*)params;

	while(1)
	{
		WaitForSingleObject(form->sync, INFINITE);
		form->port->lireport();

		std::deque<char> & buf = form->port->getRecvBuf();
		std::vector<char> trame;

		bool bFound = false;
		int idx = -1;
		// test si on est en fin de ligne de trame
		for(int i = 0; i < buf.size(); i++)
		{
			trame.push_back(buf[i]);
			if(buf[i] == '\n' || buf[i] == '\r')
			{
				idx = i + 1;
				bFound = true;
				break;
			}
		}
		// si on est en fin de ligne supprime la 1ere valeur
		if(bFound)
		{
			for(int i = 0; i < idx; i++)
			{
				buf.pop_front();
			}

			while(buf.size() > 0 && buf[0] != '$')
			{
				buf.pop_front();
            }

			form->trames.push_back(trame);
        }

		ReleaseMutex(form->sync);
	}
}



__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// charge la dll
	g_dasusbdll=LoadLibrary("DasHard2006.dll");
	// recupere l'adresse du DMX
	if(g_dasusbdll)
	{
		DasUsbCommand=(DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll,"DasUsbCommand");
	}
	// ouvre la connexion à l'interface du DMX
	interface_open=DasUsbCommand(DHC_INIT,0,NULL);
	DasUsbCommand(DHC_OPEN,0,0);

	lblResultOpenDMX->Caption=interface_open;
	// initialise les valeurs a zero
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
    // passe les 6 premieres valeurs à 255
	dmxBlock[0]=0xFF;
	dmxBlock[1]=0xFF;
	dmxBlock[2]=0xFF;
	dmxBlock[3]=0xFF;
	dmxBlock[4]=0xFF;
	dmxBlock[5]=0xFF;
	Sequence = new PilotageLumiere(dmxBlock);
    sync = CreateMutex(NULL, FALSE, NULL);
	//MessageBox(NULL,L"Connexion Reussie",L"Reussie",0);
	port = new PortLS();

//	MYSQL *conn;
//	mySQL = mysql_init(NULL);
//	conn=mysql_real_connect(mySQL, "192.168.64.67", "dmx", "dmx", "THEATRE_DMX", 0, NULL, 0);
//	std::stringstream stringbuilder;
//	if(conn==NULL)
//	{
//	}
//	else
//	{
//
//		AnsiString select = "SELECT `Nom` FROM `Course`";
//
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
//						aStr = myROW[j];
//						ListBox1->Items->Add(aStr);
//					}
//				}
//				mysql_free_result(myRES);
//			}
//		}
//	}
}


 void __fastcall TForm1::SendTrame()
 {
	if(interface_open>0)
	{

		try{
			//DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);
		}
		catch(int x)
		{
		}
	}

 }
 void __fastcall TForm1::FormClose(TObject*Sender,TCloseAction&Action)
 {
	//FermetureduDMX�l'arretduprogramme
	if(interface_open>0)
	{
		DasUsbCommand(DHC_CLOSE,0,0);
		DasUsbCommand(DHC_EXIT,0,NULL);
	}
	if(g_dasusbdll!=NULL)
	FreeLibrary(g_dasusbdll);
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarBleueChange(TObject *Sender)
{
   // recupere la valeur du curseur
   // et change la partie de la trame qui gere la couleur bleue en fonction
	Sequence->setCouleurB(255-ScrollBarBleue->Position);
	EditBleue->Text = Sequence->getCouleurB();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarVerteChange(TObject *Sender)
{
    // recupere la valeur du curseur
	// et change la partie de la trame qui gere la couleur verte en fonction
	Sequence->setCouleurG(255-ScrollBarVerte->Position);
	EditVerte->Text = Sequence->getCouleurG();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarWhiteChange(TObject *Sender)
{
    // recupere la valeur du curseur
	// et change la partie de la trame qui gere la luminosité en fonction
	Sequence->setCouleurW(255-ScrollBarWhite->Position);
	EditWhite->Text = Sequence->getCouleurW();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarRougeChange(TObject *Sender)
{
	// recupere la valeur du curseur
	// et change la partie de la trame qui gere la couleur rouge en fonction
	Sequence->setCouleurR(255-ScrollBarRouge->Position);
	EditRouge->Text = Sequence->getCouleurR();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	// execute la fonction SendTrame();
	dmxBlock[0]=Sequence->getStroboscope();
	dmxBlock[1]=Sequence->getCouleurR();
	dmxBlock[2]=Sequence->getCouleurG();
	dmxBlock[3]=Sequence->getCouleurB();
	dmxBlock[4]=Sequence->getCouleurW();
	SendTrame();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BoutonCreaSequenceClick(TObject *Sender)
{
	MYSQL *conn;
	mySQL = mysql_init(NULL);
	std::stringstream InsertSequence,InsertParametre;
	int Duree;
	int NbParametre;
	Duree = Sequence->getTimer();
	NbParametre =6;
	int Parametre1,Parametre2,Parametre3,Parametre4,Parametre5,Parametre6;
	Parametre1 =dmxBlock[0];
	Parametre2 =dmxBlock[1];
	Parametre3 =dmxBlock[2];
	Parametre4 =dmxBlock[3];
	Parametre5 =dmxBlock[4];
	Parametre6 =dmxBlock[5];

	conn=mysql_real_connect(mySQL, "192.168.65.221", "dmx", "dmx", "THEATRE_DMX", 0, NULL, 0);
	if(conn==NULL)
	{

	}
	// si la connexion à la BDD c'est bien passée
	// envoie des coordonnées dans la BDD
	else
	{
		InsertSequence << "INSERT INTO `Sequence` ( `duree`,`NB_Parametre`,`Parametre1`,`Parametre2`,`Parametre3`,`Parametre4`,`Parametre5`,`Parametre6`) VALUES ( " << Duree << ","<< NbParametre << ","<< Parametre1 << ","<< Parametre2 << ","<< Parametre3 << ","<< Parametre4 << ","<< Parametre5 <<","<< Parametre6 << ")";
		mysql_query(mySQL, InsertSequence.str().c_str());



	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	port->fermerport();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
	UnicodeString Stroboscope,Rouge,Bleu,Vert,Blanc,Timer;
	Stroboscope ="Valeur Strobo: ";
	Stroboscope+=Sequence->getStroboscope();
	Rouge = "Valeur Rouge: ";
	Rouge += Sequence->getCouleurR();
	Vert = "Valeur Vert: ";
	Vert += Sequence->getCouleurG();
	Bleu = "Valeur Bleu: ";
	Bleu += Sequence->getCouleurB();
	Blanc = "Valeur Blanc: ";
	Blanc += Sequence->getCouleurW();
	Timer = "Valeur Timer: ";
	Timer += Sequence->getTimer();
	Memo1->Clear();
	Memo1->Lines->Add(Stroboscope);
	Memo1->Lines->Add(Vert);
	Memo1->Lines->Add(Bleu);
	Memo1->Lines->Add(Blanc);
	Memo1->Lines->Add(Timer);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBarStroboChange(TObject *Sender)
{
	Sequence->setStroboscope(255-ScrollBarStrobo->Position);
	EditStrobo->Text = Sequence->getStroboscope();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ScrollBarTimerChange(TObject *Sender)
{
	Sequence->setTimer(15-ScrollBarTimer->Position);
	EditTimer->Text = Sequence->getTimer();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOFFClick(TObject *Sender)
{
	Sequence->setAllTo0();
	ScrollBarBleue->Position =255;
	ScrollBarRouge->Position =255;
	ScrollBarWhite->Position =255;
	ScrollBarVerte->Position =255;
	ScrollBarStrobo->Position =255;
	ScrollBarTimer->Position =255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int error;
	error = port->ouvrirport();

	DWORD threadId;
	CreateThread(NULL, 0, RecvThread, this, 0, &threadId);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPortSerieTimer(TObject *Sender)
{
	WaitForSingleObject(sync, INFINITE);
	UnicodeString str = "";
	int i;
	for(int j = 0; j < trames.size(); j++)
	{
		std::vector<char> buf = trames[j];
		do
		{
			str += buf[i];
			i++;
		}while (i < buf.size());
    	MemoArduino->Lines->Add(str);
	}

	trames.clear();

	ReleaseMutex(sync);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditStroboKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		ScrollBarStrobo->Position = 255-EditStrobo->Text.ToInt();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditRougeKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
	   ScrollBarRouge->Position = 255-EditRouge->Text.ToInt();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditVerteKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		  ScrollBarVerte->Position = 255-EditVerte->Text.ToInt();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditBleueKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		ScrollBarBleue->Position = 255-EditBleue->Text.ToInt();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditWhiteKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		ScrollBarWhite->Position = 255-EditWhite->Text.ToInt();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditTimerKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_RETURN)
	{
		ScrollBarTimer->Position = 15-EditTimer->Text.ToInt();
	}
}
//---------------------------------------------------------------------------

