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
    Return,  //���j���[�ɖ߂�
    GuildMenu,  //���j���[
    Up, //����
    Down,  //�����
    Set,  //�ݒu
    Guild,  //�M���h����
    Bar,  //����
    Theater,  //������
    Bath,  //�嗁��
    Dining,  //�H��
    Newspaper,  //�V�����s��
    Weapon,  //���퉮
    Armor,  //�h�
    Church,  //����
    Rifle,  //�ˌ���
    Sword,  //���p��
    Training,  //�b�B��
    Atelier,  //�A�g���G
    Library,  //�}����
    ���1,
    ���2,
    �|�[�V����,
    �Y�z,
    �T�L���o�X,
    �|����,
    ����
  };

  static int MyDrawGraph(int x, int y, int GrHandle, int TransFlag);  //�摜�̕`��
  static bool IsTouch();
  static void Clear();  //�x�N�^�[�̏�����
  static bool TouchCheck();  //�G�ꂽ���̔���
  static bool ClickCheck();  //�N���b�N�������̔���
  static std::shared_ptr<AABBInfo> GetTouch();
  static bool SetHandle(LOAD_NUM type, int handle);
  static int GetHandle(LOAD_NUM type);

  static std::map<LOAD_NUM, int> handles;  //�n���h���̈ꗗ
  static std::vector<AABBInfo> aabbInfo;  //�ÓI�����o�̐錾
  static std::shared_ptr<AABBInfo> touch;  //�G��Ă�����̂�����

private:
  AABBDraw();

};

