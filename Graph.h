#pragma once

class Graph {
public:
	Graph();
	~Graph();
	void GraphQuest_Level1(int random);
	void GraphQuest_Level2(int random1);
	enum class QuestLevel1 {
		Q1_1,///����
		Q1_2,///�̎�
		Q1_3,///�h�q
		Q1_4,///��
		Q1_5,///����
		Q1_6,///�̎�
		Q1_7,///�h�q
		Q1_8,///����
		Q1_9,///�̖�
		Q1_10,///����
	};

	enum class QuestLevel2 {
		Q2_1,///����
		Q2_2,///����
		Q2_3,///����
		Q2_4,///�̎�
		Q2_5,///�̎�
		Q2_6,///�h�q
		Q2_7,///�h�q
		Q2_8,///�h�q
		Q2_9,///��
		Q2_10,///����
		Q2_11,///��
	};


	
	void Graph_Render_Level1(QuestLevel1 index);
	void Graph_Render_Level2(QuestLevel2 index );
private:
	int quest1[10];
	int quest2[12];
};