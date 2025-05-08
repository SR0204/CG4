#pragma once
#include "KamataEngine.h"
#include"Effect.h"

using namespace KamataEngine;

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
	void EffectBorn(Vector3 position);

private:
	// エフェクト3Dモデルデータ
	Model* modelEffect_ = nullptr;

	// カメラ
	Camera camera_;

	//エフェクト
	std::list<Effect*> effects_;
};
