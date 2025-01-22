#include <stdio.h>

// 抽象クラス IShape
class IShape {
public:
    virtual void Size() = 0;  // 純粋仮想関数: 面積を計算する
    virtual void Draw() = 0;  // 純粋仮想関数: 面積を表示する

protected:
    float size;   // 面積
    float radius; // 共通で使う半径または幅の概念
};

// 円クラス Circle
class Circle : public IShape {
public:
    void Size() override {
        radius = 5.0f;
        printf("円の半径: %f\n", radius);
        size = radius * radius * 3.14f; // 円の面積: πr^2
    }
    void Draw() override { printf("円の面積: %f\n", size); }
};

// 矩形クラス Rectangle
class Rectangle : public IShape {
public:
    void Size() override {
        radius = 5.0f;
        printf("矩形の幅: %f\n", radius * 2.0f);
        size = radius * 2.0f * radius * 2.0f; // 矩形の面積: 幅×高さ
    }
    void Draw() override { printf("矩形の面積: %f\n", size); }
};

int main(void) {
    // 抽象クラスのポインタ配列を用いて動的メモリ割り当て
    IShape* ishape[2] = { new Circle(), new Rectangle() };

    // 各形状のSize()とDraw()を呼び出し
    ishape[0]->Size();
    ishape[1]->Size();

    ishape[0]->Draw();
    ishape[1]->Draw();

    // メモリ解放
    delete ishape[0];
    delete ishape[1];

    return 0;
}
