#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Stage.h"
#include"Gauge.h"
#include"Number.h"


class GameScene {

public:
	GameScene();

	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	KamataEngine::WorldTransform* worldTransform_;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* sprite2_ = nullptr;

	// メンバー変数に追加
	int frameCount = 0;

	bool isTitle = true;
	bool isBackgroundStarted_ = false;

	Stage* Stagesprite_ = nullptr;

	// プレイヤーモデル
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Model* modelPlayer_ = nullptr;

	// プレイヤーの生成
	Player* player_ = nullptr;

	// ビュープロジェクション生成
	KamataEngine::Camera* camera_;

	Gauge* gauge_ = nullptr;

	Number* number_ = nullptr;
};