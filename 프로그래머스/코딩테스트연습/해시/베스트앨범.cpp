#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    // 각 장르별로 횟수저장
    map<string, int> music;
    // 각 장르별로 무슨 노래가 몇 번씩 저장됬는지
    map<string, map<int, int>> musiclist;
    // 들어온 리스트만큼 반복
    for (int i = 0; i < genres.size(); i++)
    {
        // music map에 장르별로 횟수추가
        music[genres[i]] += plays[i];
        // musiclist map에 노래번호와 플레이횟수 추가
        musiclist[genres[i]][i] = plays[i];
    }

    // 장르가 다 없어질때까지 반복
    while (music.size() > 0)
    {
        string genre{};
        int max{};
        // 장르중에서 제일 높은 것 찾기
        for (auto mu : music)
        {
            if (max < mu.second)
            {
                max = mu.second;
                genre = mu.first;
            }
        }

        // 2곡을 넣어야하므로 2번반복
        for (int i = 0; i < 2; i++)
        {
            int val = 0, ind = -1;
            // 노래중에서 제일 높은 것 찾기
            for (auto ml : musiclist[genre])
            {
                if (val < ml.second)
                {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            // 만약 노래가 0~1곡밖에 없다면 반복문 탈출
            if (ind == -1)
                break;
            // 리턴할 리스트에 노래번호 추가
            answer.push_back(ind);
            musiclist[genre].erase(ind);
        }
        // map에서 사용한 장르 삭제
        music.erase(genre);
    }
    return answer;
}