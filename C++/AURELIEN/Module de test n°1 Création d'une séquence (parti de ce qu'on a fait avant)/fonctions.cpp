/*
	PAGE REGROUPANT LES FONCTIONS QUI CONTIENNENT LES TRAMES
	POUR CHAQUE COULEUR.
	NOUS ENVOYAONS DONC LES DIFFERENTES VALEURS DE dmxBlock[]

*/

//---------------------------------------------------------------------------

#pragma hdrstop
#include "main.h"
#include "fonctions.h"
#include <iostream>
#include <conio.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)

Couleurs::Couleurs(unsigned char * dmxBlock){
	this->dmxBlock =  dmxBlock; //constructeur
}

Couleurs::~Couleurs(){
  //destructeur
}

/*
   	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=stroboscope;
	dmxBlock[1]=rouge;
	dmxBlock[2]=vert;
	dmxBlock[3]=bleu;
	dmxBlock[4]=blanc;
	dmxBlock[5]=intensite;
*/


void Couleurs::Rouge(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=255;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}

void Couleurs::Vert(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=255;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}

void Couleurs::Bleu(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=255;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}

void Couleurs::Blanc(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}

void Couleurs::Stroboscope(){
	for (int i = 0; i < 512; i++) {
	dmxBlock[i]=0;
	}
	dmxBlock[0]=215;
	dmxBlock[1]=255;
	dmxBlock[2]=255;
	dmxBlock[3]=255;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}

void Couleurs::ON(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}

void Couleurs::OFF(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=0;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=0;
	dmxBlock[5]=0;
}

void Couleurs::Jaune(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=122;
	dmxBlock[2]=255;
	dmxBlock[3]=0;
	dmxBlock[4]=230;
	dmxBlock[5]=255;
}





