#include "Effect.h"
#include "algorithm"

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(Model* model, Vector3 posistion, Vector3 rotation, Vector3 velocity) {

	// NULLポインタチェック
	// assert(model_);

	model_ = model;
	velocity_ = velocity;

	worldTransform_.Initialize();
	worldTransform_.translation_ = posistion;
	worldTransform_.rotation_ = rotation;
	// 大きさ
	worldTransform_.scale_ = {0.1f, 6.0f, 0.0f};

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 0, 1, 1};
}

void Effect::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数を進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// 回転
	worldTransform_.rotation_ += {velocity_.x, velocity_.y, 0};

	// 行列の更新
	worldTransform_.UpdateMatrix();

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
}

void Effect::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}
