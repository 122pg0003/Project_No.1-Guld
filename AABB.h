#pragma once
#pragma once
#include<vector>
#include<memory>
#include<map>

class AABBInfo {
public:
  AABBInfo();
  AABBInfo(const AABBInfo& info);
  ~AABBInfo();
  int X;
  int Y;
  int X2;
  int Y2;
  int Handle;


};

class AABBDraw {
public:
  ~AABBDraw();

  enum class LOAD_NUM {
    Return,  //メニューに戻る
    GuildMenu,  //メニュー
    Up, //上矢印
    Down,  //下矢印
    Set,  //設置
    Guild,  //ギルド増設
    Bar,  //酒場
    Theater,  //演劇場
    Bath,  //大浴場
    Dining,  //食堂
    Newspaper,  //新聞発行所
    Weapon,  //武器屋
    Armor,  //防具屋
    Church,  //教会
    Rifle,  //射撃場
    Sword,  //剣術場
    Training,  //鍛錬場
    Atelier,  //アトリエ
    Library,  //図書館
    画面1,
    画面2,
    ポーション,
    炭鉱,
    サキュバス,
    掃除屋,
    投資
  };

  static int MyDrawGraph(int x, int y, int GrHandle, int TransFlag);  //画像の描画
  static bool IsTouch();
  static void Clear();  //ベクターの初期化
  static bool TouchCheck();  //触れたかの判定
  static bool ClickCheck();  //クリックしたかの判定
  static std::shared_ptr<AABBInfo> GetTouch();
  static bool SetHandle(LOAD_NUM type, int handle);
  static int GetHandle(LOAD_NUM type);

  static std::map<LOAD_NUM, int> handles;  //ハンドルの一覧
  static std::vector<AABBInfo> aabbInfo;  //静的メンバの宣言
  static std::shared_ptr<AABBInfo> touch;  //触れているものを入れる

private:
  AABBDraw();

};

