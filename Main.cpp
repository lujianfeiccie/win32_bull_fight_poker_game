// BullFightPoker.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GameLogic.h"
#include <windows.h>

#define NUM_OF_CARDS 52 //Except for two Kings
#define NUM_OF_PLAYER 3

int _tmain(int argc, _TCHAR* argv[])
{
 char card_char[]={'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
 Card cards[NUM_OF_CARDS];
 
 const int sizeof_card_char = sizeof(card_char)/sizeof(char);
 
 Player players[NUM_OF_PLAYER];
 for(int i=0;i<NUM_OF_PLAYER;i++){
  players[i].player = i;
  players[i].score = 0;
 }
 
 initSrand();//���������

 while(1){
  system("cls");
  printf("\n===============��ţ====================\n\n");
  initCard(card_char,sizeof_card_char,cards,NUM_OF_CARDS);
  //1.ѡׯ
  int dealer = getDealer(NUM_OF_PLAYER);
  showDealer(dealer,NUM_OF_PLAYER);
  printf("\n");
  //2.ϴ�ƺ�ÿ���˷�5����
  shuffle(cards,NUM_OF_CARDS,card_char,sizeof_card_char);
  //3.��ʾ������ҵ���
  for(int player = 0;player < NUM_OF_PLAYER;player++){
   showPlayerCards(cards,player,NUM_OF_PLAYER);
   Sleep(500);
  }
   
 
  //4.�û�ѡ��
  printf("\nλ��\t:0\t1\t2\t3\t4");
  printf("\n����λ��ѡ��������(0~4):");
  int card1,card2,card3;
  do{
   scanf("%d %d %d",&card1,&card2,&card3);
   if(card1 == card2 || card2 == card3 || card1 == card3){
    printf("λ�ò������!������ѡ��:\n");
   }else {
    break;
   }
  }while(1);
 
  //5.����ÿ����ҽ��
  printf("\n===============���====================\n\n");
  for(int player = 0;player < NUM_OF_PLAYER-1;player++){
   printf("���%d\t:",player);
   Result result = getAIResult(player,cards);
   players[player].result = result;
   showResult(result);
   Sleep(500);
  }
  printf("�Լ�\t:");
  Result result = getResult(card1,card2,card3,NUM_OF_PLAYER-1,cards);
  players[NUM_OF_PLAYER-1].result = result;
  showResult(result);
  printf("\n");

  //6.��ʾ����
  showScore(players,NUM_OF_PLAYER,dealer);
  
  //7.�Ƿ����
  printf("\n����? y or n:");
  fflush(stdin);
  if((getchar())=='n'){
   break;
  }
 }
 
 return 0;
}

