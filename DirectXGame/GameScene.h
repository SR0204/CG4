#pragma once
#include "KamataEngine.h"
#include "Model2/Model2.h"

class GameScene {

public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// モデル
	KamataEngine::Model2* model_ = nullptr;
	uint32_t textureHandle_;

	std::vector<KamataEngine::WorldTransform*> worldTransforms_;

	// カメラ
	KamataEngine::Camera* camera_;
};