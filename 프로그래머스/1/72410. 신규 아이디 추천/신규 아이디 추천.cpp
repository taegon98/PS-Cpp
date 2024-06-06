#include <string>
#include <vector>
using namespace std;

string step_1(string id) {
    for (int i = 0; i < id.size(); i++) {
        if (isupper(id[i])) {
            id[i] += 32;
        }
    }
    return id;
}

string step_2(string id) {
    string temp = "";
    
    for (int i = 0; i < id.size(); i++) {
        if (islower(id[i]) or isdigit(id[i]) or
            (id[i] == '-' or id[i] == '_' or id[i] == '.')) {
            temp += id[i];
        }
    }
    return temp;
}

string step_3(string id) {
     string temp = "";
    
    for (int i = 0; i < id.size(); i++) {
        bool flag = false;
        while (id[i] == '.') {
            flag = true;
            i++;
            
            if (i >= id.size()) {
                temp += '.';
                return temp;
            }
        }
        if (flag) temp += '.';
        temp += id[i];
    }
    return temp;
}

string step_4(string id) {
    if (id.front() == '.') {
        id = id.substr(1);
    }
    
    if (id.back() == '.') {
        id.pop_back();
    }
    return id;
}

string step_5(string id) {
    if (!id.size()) id = "a";
    return id;
}

string step_6(string id) {
    if (id.size() >= 16) {
        id = id.substr(0, 15);
        
        if (id.back() == '.') {
            id.pop_back();
        }
    }
    return id;
}

string step_7(string id) {
    if (id.size() <= 2) {
        while(id.size() < 3) {
            id += id.back();
        }
    }
    return id;
}

string solution(string new_id) {
    string answer = "";
    
    new_id = step_1(new_id);
    new_id = step_2(new_id);
    new_id = step_3(new_id);
    new_id = step_4(new_id);
    new_id = step_5(new_id);
    new_id = step_6(new_id);
    answer = step_7(new_id);
    
    return answer;
}