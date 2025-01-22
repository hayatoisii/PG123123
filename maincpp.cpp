#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
    // 山手線駅名リスト（1970年）
    list<const char*> rosen = {
        "Tabata", "Nippori", "Uguisudani", "Ueno", "Okachimachi",
        "Akihabara", "Kanda", "Tokyo", "Yurakucho", "Shimbashi",
        "Hamamatsucho", "Tamachi", "Shinagawa", "Osaki", "Gotanda",
        "Meguro", "Ebisu", "Shibuya", "Harajuku", "Yoyogi",
        "Shinjuku", "Shin-Okubo", "Takadanobaba", "Mejiro", "Ikebukuro",
        "Otsuka", "Sugamo", "Komagome"
    };

    // 1971年: 西日暮里駅を追加（NipporiとTabataの間）
    auto itr = rosen.begin();
    while (*itr != "Nippori") ++itr;
    rosen.insert(itr, "Nishi-Nippori");

    // 2020年: 高輪ゲートウェイ駅を追加（TamachiとShinagawaの間）
    itr = rosen.begin();
    while (*itr != "Shinagawa") ++itr;
    rosen.insert(itr, "Takanawa Gateway");

    // 1970年の駅一覧を表示
    cout << "Stations in 1970:" << endl;
    for (const auto& station : rosen) {
        if (station == "Nishi-Nippori" || station == "Takanawa Gateway") continue; // 1970年には存在しない駅をスキップ
        cout << station << endl;
    }

    // 2019年の駅一覧を表示
    cout << "\nStations in 2019:" << endl;
    for (const auto& station : rosen) {
        if (station == "Takanawa Gateway") continue; // 2019年には存在しない駅をスキップ
        cout << station << endl;
    }

    // 2022年の駅一覧を表示
    cout << "\nStations in 2022:" << endl;
    for (const auto& station : rosen) {
        cout << station << endl;
    }

    return 0;
}
