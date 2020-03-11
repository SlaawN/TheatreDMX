//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include<System.Classes.hpp>
#include<Vcl.Controls.hpp>
#include<Vcl.StdCtrls.hpp>
#include<Vcl.Forms.hpp>
#include<Vcl.ComCtrls.hpp>
#include<Vcl.ExtCtrls.hpp>
#include"include/DasHard.h.h"
#include "PilotageLumiere.h"
#include "LiaisonSerie.h"
#include "includeSQL/mysql.h"
#include "mysql.h"
#include <sstream>
#include <deque>
#include <vector>
#include <Windows.h>
#include <string>
#define DMX_MAXCHANNEL 512
//---------------------------------------------------------------------------
class TForm1 : public TForm
{

__published:	// Composants gérés par l'EDI
	TLabel *lblResultOpenDMX;
	TScrollBar *ScrollBarBleue;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TScrollBar *ScrollBarVerte;
	TLabel *Label4;
	TScrollBar *ScrollBarRouge;
	TScrollBar *ScrollBarWhite;
	TEdit *EditRouge;
	TEdit *EditWhite;
	TEdit *EditBleue;
	TEdit *EditVerte;
	TTimer *Timer1;
	TButton *Button1;
	TMemo *Memo1;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *EditStrobo;
	TScrollBar *ScrollBarStrobo;
	TButton *BoutonCreaSequence;
	TScrollBar *ScrollBarTimer;
	TEdit *EditTimer;
	TLabel *LabelTimer;
	TButton *ButtonOFF;
	TButton *Button2;
	TTimer *TimerPortSerie;
	TMemo *MemoArduino;
	TButton *Button3;
	void __fastcall ScrollBarBleueChange(TObject *Sender);
	void __fastcall ScrollBarVerteChange(TObject *Sender);
	void __fastcall ScrollBarWhiteChange(TObject *Sender);
	void __fastcall ScrollBarRougeChange(TObject *Sender);
	void __fastcall FormClose(TObject*Sender,TCloseAction&Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall BoutonCreaSequenceClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ScrollBarStroboChange(TObject *Sender);
	void __fastcall ScrollBarTimerChange(TObject *Sender);
	void __fastcall ButtonOFFClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall TimerPortSerieTimer(TObject *Sender);
	void __fastcall EditStroboKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditRougeKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditVerteKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditBleueKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditWhiteKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditTimerKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);








private:	// Déclarations utilisateur

	HINSTANCE g_dasusbdll;
	typedef int(*DASHARDCOMMAND)(int,int,unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];
	PilotageLumiere *Sequence;
	//void__fastcall SendTrame();
	int CouleurR;
	int CouleurG;
	int CouleurB;
	int CouleurW;
	MYSQL * mySQL;
	static DWORD WINAPI RecvThread(LPVOID param);
	HANDLE sync;
	std::deque<std::vector<char> > trames;
public:		// Déclarations utilisateur
    PortLS * port;
	__fastcall TForm1(TComponent* Owner);
	void __fastcall SendTrame();


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
