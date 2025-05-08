#pragma once
#include "KamataEngine.h"
#include"Effect.h"


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

	//エフェクト発生
	void EffectBorn(KamataEngine::Vector3 position);

private:
	// エフェクト3Dモデルデータ
	KamataEngine::Model* modelEffect_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	//エフェクト
	std::list<Effect*> effects_;
};
