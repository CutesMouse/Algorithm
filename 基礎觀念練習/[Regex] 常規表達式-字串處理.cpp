#include <regex>
#include <iostream>
using namespace std;
int main()
{
    // 建立新的regex
    regex reg1("[A-Z]\\d");

    // regex_match(string,regex)
    // 檢查字串是否符合regex，
    // 相當於Java之 "String.match(reg)"

    cout << regex_match("H1",reg1) << "\n";
    // 因為H1符合規定，輸出 '1'

    cout << regex_match("banana",reg1) << "\n";
    // 不符合大寫字母+數字的規定，輸出0

    regex reg2("get\\s(.+?)\\s");
    string st1 = "get pie ";
    smatch sm1;
    // regex_match(string,smatch,regex)
    // 檢查"整個"字串是否符合regex
    // 需要整個字串都滿足regex才會回傳true
    // 用法和沒有smatch時大同小異
    // 並將符合規定之字串放進smatch中
    // 也可使用 () 將字串內容取出
    if (regex_match(st1,sm1,reg2))
    {
        cout << sm1[1] << "\n"; // 輸出 pie
        // sm1[0] 是原始字串
        // sm1[1] 才為括號內文字
    }

    string st2 = "I'd like to get pie and get cake for dinner.";
    // regex_search(string,smatch,regex)
    // 用法、概念和regex_match差不多
    // 但search搜尋的是一個大字串內符合條件的"子字串"
    while (regex_search(st2,sm1,reg2))
    {
        cout << sm1[1] << "\n";
        // 這邊要注意，已經搜尋過的子字串不會因為被搜尋過
        // 而自動被標記刪除
        // 而是需要手動更新刪除後的子字串
        // 這裡使用 smatch.suffix.str 來更新原字串
        // 使原始字串越來越短
        st2 = sm1.suffix().str();
    }
    // 上面執行完成後輸出 "pie\ncake";

    string st3 = "Sandy and Benson are two of my best friends.";
    regex reg3("Sandy|Benson");
    // regex_replace(string,regex,string)
    // 取代掉符合regex的子字串
    // 類似於Java中的 "String.replaceAll()"

    cout << regex_replace(st3,reg3,"(name)") << "\n";
    // 將 "Sandy" 和 "Benson" 替換掉，將輸出
    // (name) and (name) are two of my best friends.
}
