#pragma once
#include"KamataEngine.h"

using namespace KamataEngine;

class Effect {

public:
	void Initialize(Model* model, Vector3 rotation, Vector3 velocity);

	void Update();

	void Draw(Camera&camera);

private:

	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// 移動量
	Vector3 velocity_;
};
