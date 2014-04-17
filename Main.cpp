// BullFightPoker.cpp : 定义控制台应用程序的入口点。
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
 
 initSrand();//随机数种子

 while(1){
  system("cls");
  printf("\n===============斗牛====================\n\n");
  initCard(card_char,sizeof_card_char,cards,NUM_OF_CARDS);
  //1.选庄
  int dealer = getDealer(NUM_OF_PLAYER);
  showDealer(dealer,NUM_OF_PLAYER);
  printf("\n");
  //2.洗牌后，每个人发5张牌
  shuffle(cards,NUM_OF_CARDS,card_char,sizeof_card_char);
  //3.显示所有玩家的牌
  for(int player = 0;player < NUM_OF_PLAYER;player++){
   showPlayerCards(cards,player,NUM_OF_PLAYER);
   Sleep(500);
  }
   
 
  //4.用户选牌
  printf("\n位置\t:0\t1\t2\t3\t4");
  printf("\n根据位置选择三张牌(0~4):");
  int card1,card2,card3;
  do{
   scanf("%d %d %d",&card1,&card2,&card3);
   if(card1 == card2 || card2 == card3 || card1 == card3){
    printf("位置不能相等!请重新选择:\n");
   }else {
    break;
   }
  }while(1);
 
  //5.计算每个玩家结果
  printf("\n===============结果====================\n\n");
  for(int player = 0;player < NUM_OF_PLAYER-1;player++){
   printf("玩家%d\t:",player);
   Result result = getAIResult(player,cards);
   players[player].result = result;
   showResult(result);
   Sleep(500);
  }
  printf("自己\t:");
  Result result = getResult(card1,card2,card3,NUM_OF_PLAYER-1,cards);
  players[NUM_OF_PLAYER-1].result = result;
  showResult(result);
  printf("\n");

  //6.显示分数
  showScore(players,NUM_OF_PLAYER,dealer);
  
  //7.是否继续
  printf("\n继续? y or n:");
  fflush(stdin);
  if((getchar())=='n'){
   break;
  }
 }
 
 return 0;
}

