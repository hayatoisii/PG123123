#include <iostream>
using namespace std;

class Enemy {
public:
    void update();
    void approach(); // 接近状態
    void attack();   // 攻撃状態
    void retreat();  // 離脱状態

    // メンバ関数ポインタのテーブル
    static void (Enemy::* table[])();
private:
    int index = 0; // 現在の状態を表すインデックス
};

void Enemy::approach() {
    cout << "敵が接近！" << endl;
}

void Enemy::attack() {
    cout << "敵が攻撃！" << endl;
}

void Enemy::retreat() {
    cout << "敵が離脱" << endl;
}

void Enemy::update() {
    // 関数ポインタのテーブルから関数を実行
    (this->*table[index])();

    cout << "次の状態に移行 (0: はい、 他: いいえ)";
    int input;
    cin >> input;

    if (input == 0) {
        index = (index + 1) % 3;
    }
}

// static メンバ関数ポインタテーブルの実体化
void (Enemy::* Enemy::table[])() = {
    &Enemy::approach, // インデックス番号0
    &Enemy::attack,   // インデックス番号1
    &Enemy::retreat   // インデックス番号2
};

int main() {
    Enemy enemy;

    while (true) {
        enemy.update();
    }

    return 0;
}