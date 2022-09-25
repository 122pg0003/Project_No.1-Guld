#include"Graph.h"
#include"DxLib.h"

Graph::Graph() {
  ///レベル１
  Quest_Slot[1] = LoadGraph("images/to-batu_s1.png");///討伐クエストスロット
  Quest_Slot[2] = LoadGraph("images/saishu_s1.png");///採取クエストスロット
  Quest_Slot[3] = LoadGraph("images/bo-ei_s1.png");///防衛クエストスロット
  Quest_Slot[4] = LoadGraph("images/others_s1.png");///他クエストスロット

  ///レベル２
  Quest_Slot[5] = LoadGraph("images/to-batu_s2.png");///討伐クエストスロット
  Quest_Slot[6] = LoadGraph("images/saishu_s2.png");///採取クエストスロット
  Quest_Slot[7] = LoadGraph("images/bo-ei_s2.png");///防衛クエストスロット
  Quest_Slot[8] = LoadGraph("images/others_s2.png");///他クエストスロット
  
  ///レベル3
    Quest_Slot[9] = LoadGraph("images/to-batu_s3.png");///討伐クエストスロット
    Quest_Slot[10] = LoadGraph("images/saishu_s3.png");///採取クエストスロット
    Quest_Slot[11] = LoadGraph("images/bo-ei_s3.png");///防衛クエストスロット
    Quest_Slot[12] = LoadGraph("images/others_s3.png");///他クエストスロット
  
  ///レベル4
  Quest_Slot[13] = LoadGraph("images/to-batu_s4.png");///討伐クエストスロット
  Quest_Slot[14] = LoadGraph("images/saishu_s4.png");///採取クエストスロット
  Quest_Slot[15] = LoadGraph("images/bo-ei_s4.png");///防衛クエストスロット
  Quest_Slot[16] = LoadGraph("images/others_s4.png");///他クエストスロット
  
  ///レベル5
  Quest_Slot[17] = LoadGraph("images/to-batu_s5.png");///討伐クエストスロット
  Quest_Slot[18] = LoadGraph("images/saishu_s5.png");///採取クエストスロット
  Quest_Slot[19] = LoadGraph("images/bo-ei_s5.png");///防衛クエストスロット
  Quest_Slot[20] = LoadGraph("images/others_s5.png");///他クエストスロット
  
  ///レベル1
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
	
  ///レベル2
	quest1[11]= LoadGraph("images/quest2-1.png");
	quest1[12]= LoadGraph("images/quest2-2.png");
	quest1[13]= LoadGraph("images/quest2-3.png");
	quest1[14]= LoadGraph("images/quest2-4.png");
	quest1[15]= LoadGraph("images/quest2-5.png");
	quest1[16]= LoadGraph("images/quest2-6.png");
	quest1[17]= LoadGraph("images/quest2-7.png");
	quest1[18]= LoadGraph("images/quest2-8.png");
	quest1[19] = LoadGraph("images/quest2-9.png");
	quest1[20] = LoadGraph("images/quest2-10.png");
	quest1[21] = LoadGraph("images/quest2-11.png");
	quest1[22] = LoadGraph("images/quest2-12.png");

  ///レベル3
  quest1[23] = LoadGraph("images/quest3-1.png");
  quest1[24] = LoadGraph("images/quest3-2.png");
  quest1[25] = LoadGraph("images/quest3-3.png");
  quest1[26] = LoadGraph("images/quest3-4.png");
  quest1[27] = LoadGraph("images/quest3-5.png");
  quest1[28] = LoadGraph("images/quest3-6.png");
  quest1[29] = LoadGraph("images/quest3-7.png");
  quest1[30] = LoadGraph("images/quest3-8.png");
  quest1[31] = LoadGraph("images/quest3-9.png");
  quest1[32] = LoadGraph("images/quest3-10.png");
  quest1[33] = LoadGraph("images/quest3-11.png");
  quest1[34] = LoadGraph("images/quest3-12.png");
  quest1[35] = LoadGraph("images/quest3-13.png");
  quest1[36] = LoadGraph("images/quest3-14.png");
  quest1[37] = LoadGraph("images/quest3-15.png");
  quest1[38] = LoadGraph("images/quest3-16.png");
  quest1[39] = LoadGraph("images/quest3-17.png");

  ///レベル4
  quest1[40] = LoadGraph("images/quest4-1.png");
  quest1[41] = LoadGraph("images/quest4-2.png");
  quest1[42] = LoadGraph("images/quest4-3.png");
  quest1[43] = LoadGraph("images/quest4-4.png");
  quest1[44] = LoadGraph("images/quest4-5.png");
  quest1[45] = LoadGraph("images/quest4-6.png");
  quest1[46] = LoadGraph("images/quest4-7.png");
  quest1[47] = LoadGraph("images/quest4-8.png");
  quest1[48] = LoadGraph("images/quest4-9.png");
  quest1[49] = LoadGraph("images/quest4-10.png");
  quest1[50] = LoadGraph("images/quest4-11.png");
  quest1[51] = LoadGraph("images/quest4-12.png");
  quest1[52] = LoadGraph("images/quest4-13.png");
  quest1[53] = LoadGraph("images/quest4-14.png");
  quest1[54] = LoadGraph("images/quest4-15.png");
  quest1[55] = LoadGraph("images/quest4-16.png");
  quest1[56] = LoadGraph("images/quest4-17.png");

  ///レベル5
  quest1[57] = LoadGraph("images/quest5-1.png");
  quest1[58] = LoadGraph("images/quest5-2.png");
  quest1[59] = LoadGraph("images/quest5-3.png");
  quest1[60] = LoadGraph("images/quest5-4.png");
  quest1[61] = LoadGraph("images/quest5-5.png");
  quest1[62] = LoadGraph("images/quest5-6.png");
  quest1[63] = LoadGraph("images/quest5-7.png");
  quest1[64] = LoadGraph("images/quest5-8.png");
  quest1[65] = LoadGraph("images/quest5-9.png");
  quest1[66] = LoadGraph("images/quest5-10.png");
  quest1[67] = LoadGraph("images/quest5-11.png");
  quest1[68] = LoadGraph("images/quest5-12.png");
  quest1[69] = LoadGraph("images/quest5-13.png");
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

    ///レベル2
  case 11:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 12:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 13:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 14:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 15:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 16:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 17:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 18:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 19:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 20:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;
  case 21:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 22:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;

    ///レベル3
  case 23:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 24:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 25:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 26:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 27:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 28:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 29:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 30:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 31:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 32:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛エスト
    break;
  case 33:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 34:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 35:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 36:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
      break;
    case 37:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
      break;
    case 38:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
      break;
    case 39:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
      break;

      ///レベル4
    case 40:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 41:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 42:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 43:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 44:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 45:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 46:
      DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
      break;
    case 47:
      DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
      break;
    case 48:
      DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
      break;
    case 49:
      DrawGraph(x, y, Quest_Slot[14], TRUE);///採取エスト
      break;
    case 50:
      DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
      break;
    case 51:
      DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
      break;
    case 52:
      DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
      break;
    case 53:
      DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
      break;
    case 54:
      DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
      break;
    case 55:
      DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
      break;
    case 56:
      DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
      break;

      ///レベル5
     case 57:
      DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
      break;
     case 58:
       DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
       break;
     case 59:
       DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
       break;
     case 60:
       DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
       break;
     case 61:
       DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
       break;
     case 62:
       DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
       break;
     case 63:
       DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
       break;
     case 64:
       DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
       break;
     case 65:
       DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
       break;
     case 66:
       DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
       break;
     case 67:
       DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
       break;
     case 68:
       DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
       break;
     case 69:
       DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
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

    ///レベル2
  case 11:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 12:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 13:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 14:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 15:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 16:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 17:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 18:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 19:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 20:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;
  case 21:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 22:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;

    ///レベル3
  case 23:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 24:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 25:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 26:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 27:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 28:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 29:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 30:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 31:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 32:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛エスト
    break;
  case 33:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 34:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 35:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 36:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 37:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 38:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 39:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;

    ///レベル4
  case 40:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 41:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 42:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 43:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 44:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 45:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 46:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 47:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 48:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 49:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取エスト
    break;
  case 50:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 51:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 52:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 53:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 54:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 55:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;
  case 56:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;

    ///レベル5
  case 57:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 58:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 59:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 60:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 61:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 62:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 63:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 64:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 65:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 66:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 67:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 68:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 69:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
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

    ///レベル2
  case 11:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 12:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 13:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 14:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 15:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 16:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 17:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 18:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 19:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 20:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;
  case 21:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 22:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;

    ///レベル3
  case 23:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 24:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 25:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 26:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 27:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 28:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 29:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 30:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 31:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 32:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛エスト
    break;
  case 33:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 34:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 35:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 36:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 37:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 38:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 39:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;

    ///レベル4
  case 40:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 41:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 42:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 43:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 44:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 45:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 46:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 47:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 48:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 49:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取エスト
    break;
  case 50:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 51:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 52:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 53:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 54:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 55:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;
  case 56:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;

    ///レベル5
  case 57:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 58:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 59:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 60:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 61:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 62:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 63:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 64:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 65:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 66:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 67:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 68:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 69:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
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

    ///レベル2
  case 11:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 12:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 13:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 14:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 15:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 16:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 17:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 18:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 19:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 20:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;
  case 21:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 22:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;

    ///レベル3
  case 23:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 24:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 25:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 26:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 27:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 28:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 29:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 30:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 31:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 32:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛エスト
    break;
  case 33:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 34:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 35:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 36:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 37:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 38:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 39:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;

    ///レベル4
  case 40:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 41:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 42:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 43:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 44:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 45:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 46:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 47:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 48:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 49:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取エスト
    break;
  case 50:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 51:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 52:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 53:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 54:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 55:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;
  case 56:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;

    ///レベル5
  case 57:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 58:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 59:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 60:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 61:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 62:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 63:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 64:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 65:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 66:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 67:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 68:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 69:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
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

    ///レベル2
  case 11:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 12:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 13:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 14:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 15:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 16:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 17:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 18:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 19:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 20:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;
  case 21:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 22:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;

    ///レベル3
  case 23:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 24:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 25:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 26:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 27:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 28:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 29:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 30:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 31:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 32:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛エスト
    break;
  case 33:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 34:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 35:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 36:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 37:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 38:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 39:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;

    ///レベル4
  case 40:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 41:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 42:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 43:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 44:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 45:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 46:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 47:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 48:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 49:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取エスト
    break;
  case 50:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 51:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 52:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 53:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 54:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 55:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;
  case 56:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;

    ///レベル5
  case 57:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 58:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 59:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 60:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 61:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 62:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 63:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 64:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 65:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 66:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 67:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 68:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 69:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
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

    ///レベル2
  case 11:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 12:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 13:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 14:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 15:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 16:
    DrawGraph(x, y, Quest_Slot[6], TRUE);///採取クエスト
    break;
  case 17:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 18:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 19:
    DrawGraph(x, y, Quest_Slot[7], TRUE);///防衛クエスト
    break;
  case 20:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;
  case 21:
    DrawGraph(x, y, Quest_Slot[5], TRUE);///討伐クエスト
    break;
  case 22:
    DrawGraph(x, y, Quest_Slot[8], TRUE);///他クエスト
    break;

    ///レベル3
  case 23:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 24:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 25:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 26:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 27:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 28:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 29:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 30:
    DrawGraph(x, y, Quest_Slot[10], TRUE);///採取クエスト
    break;
  case 31:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 32:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛エスト
    break;
  case 33:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 34:
    DrawGraph(x, y, Quest_Slot[11], TRUE);///防衛クエスト
    break;
  case 35:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 36:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 37:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;
  case 38:
    DrawGraph(x, y, Quest_Slot[9], TRUE);///討伐クエスト
    break;
  case 39:
    DrawGraph(x, y, Quest_Slot[12], TRUE);///他クエスト
    break;

    ///レベル4
  case 40:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 41:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 42:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 43:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 44:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 45:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 46:
    DrawGraph(x, y, Quest_Slot[13], TRUE);///討伐クエスト
    break;
  case 47:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 48:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 49:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取エスト
    break;
  case 50:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 51:
    DrawGraph(x, y, Quest_Slot[14], TRUE);///採取クエスト
    break;
  case 52:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 53:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 54:
    DrawGraph(x, y, Quest_Slot[15], TRUE);///防衛クエスト
    break;
  case 55:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;
  case 56:
    DrawGraph(x, y, Quest_Slot[16], TRUE);///他クエスト
    break;

    ///レベル5
  case 57:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 58:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 59:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 60:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 61:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 62:
    DrawGraph(x, y, Quest_Slot[17], TRUE);///討伐クエスト
    break;
  case 63:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 64:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 65:
    DrawGraph(x, y, Quest_Slot[18], TRUE);///採取クエスト
    break;
  case 66:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 67:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 68:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;
  case 69:
    DrawGraph(x, y, Quest_Slot[19], TRUE);///防衛クエスト
    break;

  }
}


void Graph::GraphQuest_Level1(int random) {
  switch (random)
  {
    ///レベル1
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

    ///レベル2
  case 11:
    DrawGraph(0, 0, quest1[11], TRUE);
    break;
  case 12:
    DrawGraph(0, 0, quest1[12], TRUE);
    break;
  case 13:
    DrawGraph(0, 0, quest1[13], TRUE);
    break;
  case 14:
    DrawGraph(0, 0, quest1[14], TRUE);
    break;
  case 15:
    DrawGraph(0, 0, quest1[15], TRUE);
    break;
  case 16:
    DrawGraph(0, 0, quest1[16], TRUE);
    break;
  case 17:
    DrawGraph(0, 0, quest1[17], TRUE);
    break;
  case 18:
    DrawGraph(0, 0, quest1[18], TRUE);
    break;
  case 19:
    DrawGraph(0, 0, quest1[19], TRUE);
    break;
  case 20:
    DrawGraph(0, 0, quest1[20], TRUE);
    break;
  case 21:
    DrawGraph(0, 0, quest1[21], TRUE);
    break;
  case 22:
    DrawGraph(0, 0, quest1[22], TRUE);
    break;

    ///レベル3
  case 23:
    DrawGraph(0, 0, quest1[23], TRUE);
    break;
  case 24:
    DrawGraph(0, 0, quest1[24], TRUE);
    break;
  case 25:
    DrawGraph(0, 0, quest1[25], TRUE);
    break;
  case 26:
    DrawGraph(0, 0, quest1[26], TRUE);
    break;
  case 27:
    DrawGraph(0, 0, quest1[27], TRUE);
    break;
  case 28:
    DrawGraph(0, 0, quest1[28], TRUE);
    break;
  case 29:
    DrawGraph(0, 0, quest1[29], TRUE);
    break;
  case 30:
    DrawGraph(0, 0, quest1[30], TRUE);
    break;
  case 31:
    DrawGraph(0, 0, quest1[31], TRUE);
    break;
  case 32:
    DrawGraph(0, 0, quest1[32], TRUE);
    break;
  case 33:
    DrawGraph(0, 0, quest1[33], TRUE);
    break;
  case 34:
    DrawGraph(0, 0, quest1[34], TRUE);
    break;
  case 35:
    DrawGraph(0, 0, quest1[35], TRUE);
    break;
  case 36:
    DrawGraph(0, 0, quest1[36], TRUE);
    break;
  case 37:
    DrawGraph(0, 0, quest1[37], TRUE);
    break;
  case 38:
    DrawGraph(0, 0, quest1[38], TRUE);
    break;
  case 39:
    DrawGraph(0, 0, quest1[39], TRUE);
    break;

    ///レベル4
  case 40:
    DrawGraph(0, 0, quest1[40], TRUE);
    break;
  case 41:
    DrawGraph(0, 0, quest1[41], TRUE);
    break;
  case 42:
    DrawGraph(0, 0, quest1[42], TRUE);
    break;
  case 43:
    DrawGraph(0, 0, quest1[43], TRUE);
    break;
  case 44:
    DrawGraph(0, 0, quest1[44], TRUE);
    break;
  case 45:
    DrawGraph(0, 0, quest1[45], TRUE);
    break;
  case 46:
    DrawGraph(0, 0, quest1[46], TRUE);
    break;
  case 47:
    DrawGraph(0, 0, quest1[47], TRUE);
    break;
  case 48:
    DrawGraph(0, 0, quest1[48], TRUE);
    break;
  case 49:
    DrawGraph(0, 0, quest1[49], TRUE);
    break;
  case 50:
    DrawGraph(0, 0, quest1[50], TRUE);
    break;
  case 51:
    DrawGraph(0, 0, quest1[51], TRUE);
    break;
  case 52:
    DrawGraph(0, 0, quest1[52], TRUE);
    break;
  case 53:
    DrawGraph(0, 0, quest1[53], TRUE);
    break;
  case 54:
    DrawGraph(0, 0, quest1[54], TRUE);
    break;
  case 55:
    DrawGraph(0, 0, quest1[55], TRUE);
    break;
  case 56:
    DrawGraph(0, 0, quest1[56], TRUE);
    break;

    ///レベル5
  case 57:
    DrawGraph(0, 0, quest1[57], TRUE);
    break;
  case 58:
    DrawGraph(0, 0, quest1[58], TRUE);
    break;
  case 59:
    DrawGraph(0, 0, quest1[59], TRUE);
    break;
  case 60:
    DrawGraph(0, 0, quest1[60], TRUE);
    break;
  case 61:
    DrawGraph(0, 0, quest1[61], TRUE);
    break;
  case 62:
    DrawGraph(0, 0, quest1[62], TRUE);
    break;
  case 63:
    DrawGraph(0, 0, quest1[63], TRUE);
    break;
  case 64:
    DrawGraph(0, 0, quest1[64], TRUE);
    break;
  case 65:
    DrawGraph(0, 0, quest1[65], TRUE);
    break;
  case 66:
    DrawGraph(0, 0, quest1[66], TRUE);
    break;
  case 67:
    DrawGraph(0, 0, quest1[67], TRUE);
    break;
  case 68:
    DrawGraph(0, 0, quest1[68], TRUE);
    break;
  case 69:
    DrawGraph(0, 0, quest1[69], TRUE);
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
