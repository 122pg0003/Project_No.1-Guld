#include"Graph.h"
#include"DxLib.h"

Graph::Graph() {
  Quest_Slot[1] = LoadGraph("images/to-batu_s1.png");///討伐クエストスロット
  Quest_Slot[2] = LoadGraph("images/saishu_s1.png");///採取クエストスロット
  Quest_Slot[3] = LoadGraph("images/bo-ei_s1.png");///防衛クエストスロット
  Quest_Slot[4] = LoadGraph("images/others_s1.png");///他クエストスロット



	quest1[1] = LoadGraph("images/quest1_1.png");
	quest1[2] = LoadGraph("images/quest1_2.png");
	quest1[3] = LoadGraph("images/quest1_3.png");
	quest1[4] = LoadGraph("images/quest1_4.png");
	quest1[5] = LoadGraph("images/quest1_5.png");
	quest1[6] = LoadGraph("images/quest1_6.png");
	quest1[7] = LoadGraph("images/quest1_7.png");
	quest1[8] = LoadGraph("images/quest1_8.png");
	quest1[9] = LoadGraph("images/quest1_9.png");
	quest1[10] = LoadGraph("images/quest1_10.png");
	

	quest2[1]= LoadGraph("images/quest2-1.png");
	quest2[2]= LoadGraph("images/quest2-2.png");
	quest2[3]= LoadGraph("images/quest2-3.png");
	quest2[4]= LoadGraph("images/quest2-5.png");
	quest2[5]= LoadGraph("images/quest2-6.png");
	quest2[6]= LoadGraph("images/quest2-7.png");
	quest2[7]= LoadGraph("images/quest2-8.png");
	quest2[8]= LoadGraph("images/quest2-9.png");
	quest2[9] = LoadGraph("images/quest2_10.png");
	quest2[10] = LoadGraph("images/quest2_11.png");
	quest2[11] = LoadGraph("images/quest2_12.png");


}

Graph::~Graph() {

}

void Graph::Quest_Slot_Level1(int random) {
  int x = 396;
  int y = 270;
  switch (random) {
  case 1:
    DrawGraph(x,y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 2:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
      break;
  case 3:
    DrawGraph(x, y,  Quest_Slot[3], TRUE);///防衛クエスト
        break;
  case 4:
    DrawGraph(x, y,  Quest_Slot[4], TRUE);///他クエスト
          break;
  case 5:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
            break;
  case 6:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
              break;
  case 7:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 8:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 9:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 10:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  }
}
void Graph::Quest_Slot_Level1_2(int random1) {
  int x = 830;
  int y = 270;
  switch (random1) {
  case 1:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 2:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 3:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 4:
    DrawGraph(x, y, Quest_Slot[4], TRUE);///他クエスト
    break;
  case 5:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 6:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 7:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 8:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 9:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 10:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  }
}
void Graph::Quest_Slot_Level1_3(int random2) {
  int x = 1264;
  int y = 270;
  switch (random2) {
  case 1:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 2:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 3:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 4:
    DrawGraph(x, y, Quest_Slot[4], TRUE);///他クエスト
    break;
  case 5:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 6:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 7:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 8:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 9:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 10:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  }
}
void Graph::Quest_Slot_Level1_4(int random3) {
  int x = 396;
  int y = 640;
  switch (random3) {
  case 1:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 2:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 3:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 4:
    DrawGraph(x, y, Quest_Slot[4], TRUE);///他クエスト
    break;
  case 5:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 6:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 7:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 8:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 9:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 10:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  }
}
void Graph::Quest_Slot_Level1_5(int random4) {
  int x = 830;
  int y = 640;
  switch (random4) {
  case 1:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 2:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 3:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 4:
    DrawGraph(x, y, Quest_Slot[4], TRUE);///他クエスト
    break;
  case 5:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 6:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 7:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 8:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 9:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 10:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  }
}
void Graph::Quest_Slot_Level1_6(int random5) {
  int x = 1264;
  int y = 640;
  switch (random5) {
  case 1:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 2:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 3:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 4:
    DrawGraph(x, y, Quest_Slot[4], TRUE);///他クエスト
    break;
  case 5:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 6:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 7:
    DrawGraph(x, y, Quest_Slot[3], TRUE);///防衛クエスト
    break;
  case 8:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  case 9:
    DrawGraph(x, y, Quest_Slot[2], TRUE);///採取クエスト
    break;
  case 10:
    DrawGraph(x, y, Quest_Slot[1], TRUE);///討伐クエスト
    break;
  }
}


void Graph::GraphQuest_Level1(int random) {
  switch (random)
  {
  case 1:
    DrawGraph(0, 0, quest1[1], TRUE);
    break;
  case 2:
    DrawGraph(0, 0, quest1[2], TRUE);
    break;
  case 3:
    DrawGraph(0, 0, quest1[3], TRUE);
    break;
  case 4:
    DrawGraph(0, 0, quest1[4], TRUE);
    break;
  case 5:
    DrawGraph(0, 0, quest1[5], TRUE);
    break;
  case 6:
    DrawGraph(0, 0, quest1[6], TRUE);
    break;
  case 7:
    DrawGraph(0, 0, quest1[7], TRUE);
    break;
  case 8:
    DrawGraph(0, 0, quest1[8], TRUE);
    break;
  case 9:
    DrawGraph(0, 0, quest1[9], TRUE);
    break;
  case 10:
    DrawGraph(0, 0, quest1[10], TRUE);
    break;
  }
}



void Graph::Graph_Render_Level2(QuestLevel2 index) {
	switch (index)
              	{
              	case QuestLevel2::Q2_1:
              		DrawGraph(0, 0, quest2[1], TRUE);
              		break;
              
              	case QuestLevel2::Q2_2:
              		DrawGraph(0, 0, quest2[2], TRUE);
              		break;
              
              	case QuestLevel2::Q2_3:
              		DrawGraph(0, 0, quest2[3], TRUE);
              		break;
              
              	case QuestLevel2::Q2_4:
              		DrawGraph(0, 0, quest2[4], TRUE);
              		break;
              
              	case QuestLevel2::Q2_5:
              		DrawGraph(0, 0, quest2[5], TRUE);
              		break;
              
              	case QuestLevel2::Q2_6:
              		DrawGraph(0, 0, quest2[6], TRUE);
              		break;
              
              	case QuestLevel2::Q2_7:
              		DrawGraph(0, 0, quest2[7], TRUE);
              		break;
              
              	case QuestLevel2::Q2_8:
              		DrawGraph(0, 0, quest2[8], TRUE);
              		break;
              
              	case QuestLevel2::Q2_9:
              		DrawGraph(0, 0, quest2[9], TRUE);
              		break;
              
              	case QuestLevel2::Q2_10:
              		DrawGraph(0, 0, quest2[10], TRUE);
              		break;
              
              	case QuestLevel2::Q2_11:
              		DrawGraph(0, 0, quest2[11], TRUE);
              		break;


	}

}
