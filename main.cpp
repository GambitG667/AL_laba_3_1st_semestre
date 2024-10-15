#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <string>


void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
void task_7();
void task_8();
void task_9();
void task_10();
void task_11();
void menu();
int length(std::string);


/*

Не стал перегружать функции для разных типов, написал просто через шаблон \(o_o)/

*/

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist] () -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

template<class T>
void print_vector(std::vector<T> vector){
    for(auto i: vector){
        std::cout << i<< ' ';
    }
    std::cout << std::endl;
}

template<class T>
void swap(std::vector<T> &vector, int first, int second){
    T bufer = vector.at(first);
    vector.at(first) = vector.at(second);
    vector.at(second) = bufer;
}



int main(){

    while(true) menu();

    return 0;
}

void menu(){
    std::cout << "Выберите программу от 1 до 11. -1 чтобы выйти: ";
    int input{-1};
    std::cin >>input;

    switch (input) {
        case -1:{
            return;
        }
        case 1:{
            task_1();
            break;
        };
        case 2:{
            task_2();
            break;
        };  
        case 3:{
            task_3();
            break;
        };
        case 4:{
            task_4();
            break;
        };
        case 5:{
            task_5();
            break;
        };
        case 6:{
            task_6();
            break;
        };
        case 7:{
            task_7();
            break;
        };
        case 8:{
            task_8();
            break;
        };
        case 9:{
            task_9();
            break;
        };
        case 10:{
            task_10();
            break;
        };
        case 11:{
            task_11();
            break;
        };
    }
}

int length(std::string str){
    int i = 0;
    int count = 0;
    while(str[i++] != '\0') ++count;
    return count;
}

void task_1(){
    float a{};
    std::cout << "введите число a: ";
    std::cin >> a;
    std::vector<float> vector = generate_random_vector<float>(10,1,100);
    
    std::cout << "Исходный массив:\n";
    print_vector(vector);

    std::vector<float> vector2(vector);
    for(int i{}; i < vector2.size(); ++i){
        vector2.at(i) = vector.at(i)*2;
    }

    std::cout << "Массив с удвоенными элементами:\n";
    print_vector(vector2);

    std::vector<float> vector3(vector);
    for(int i{}; i < vector3.size(); ++i){
        vector3.at(i) = vector.at(i)-a;
    }

    std::cout << "Массив с элементами уменьшеными на a:\n";
    print_vector(vector3);

    std::vector<float> vector4(vector);
    for(int i{}; i < vector4.size(); ++i){
        vector4.at(i) = vector.at(i)/vector.at(0);
    }

    std::cout << "Массив с элементами поделенными на первый элемент:\n";
    print_vector(vector4);
}

void task_2(){
    std::vector<int> vector = generate_random_vector<int>(20);
    int k1, k2;
    int s1, s2;

    std::cout << "Введите k1 и k2: ";
    std::cin >> k1 >> k2;

    std::cout << "Введите s1 и s2: ";
    std::cin >> s1 >> s2;
        
    int summ_elements{};
    int summ_squares{};
    int summ_first_six{};
    int summ_from_k1_to_k2{};
    float average_all{};
    float average_from_s1_to_s2{};

    for(int i: vector) summ_elements += i;
    for(int i: vector) summ_squares += i*i;
    for(int i{}; i < 6; ++i) summ_first_six += vector.at(i);
    for(int i{k1}; i <= k2; ++i) summ_from_k1_to_k2 += vector.at(i);
    average_all = float(summ_elements) / vector.size();
    for(int i{s1}; i <= s2; ++i) average_from_s1_to_s2 += vector.at(i);
    average_from_s1_to_s2 /= (s2 - s1 + 1);

    std::cout << "Исходный вектор\n";
    print_vector(vector);
    std::cout << "Сумма элементов "<< summ_elements << '\n';
    std::cout << "Сумма квадратов элементов "<< summ_squares << '\n';
    std::cout << "Сумма первых 6 "<< summ_first_six << '\n';
    std::cout << "Сумма элементов от k1 до k2 "<< summ_from_k1_to_k2 << '\n';
    std::cout << "Среднее арифметическое "<< average_all << '\n';
    std::cout << "Среднее арифметическое от s1 до s2 "<< average_from_s1_to_s2<< '\n';
    
}
void task_3(){
    std::vector<int> vector = generate_random_vector<int>(20);
    std::cout << "Исходный вектор\n";
    print_vector(vector);
    for(int i{}; i < 3; ++i) swap(vector, i, vector.size()-3+i);
    std::cout << "Результат\n";
    print_vector(vector);
}   
void task_4(){
    std::vector<int> vector = generate_random_vector<int>(20);
    std::vector<int> new_vector;
    new_vector.reserve(vector.size());
    for(int i{}, flag{}; i < vector.size(); ++i){
        if(flag == 0 && vector.at(i) < 0) flag = 1;
        else new_vector.push_back(vector.at(i));
    }
    std::vector<int> result_vector;
    result_vector.reserve(new_vector.size());
    for(int i = new_vector.size() - 1, flag{}; i >= 0; --i){
        if(flag == 0 && new_vector.at(i) % 2  == 0) flag = 1;
        else result_vector.insert(result_vector.begin(), new_vector.at(i));
    }
    std::cout << "Исходный вектор\n";
    print_vector(vector);
    std::cout << "Результат\n";
    print_vector(result_vector);
}
void task_5(){
    std::string name;
    std::cout << "Введите имя, латиницей, с кирилицей в зависимости от компилятора могут быть проблемы\n";
    std::cin >> name;
    if(length(name) % 2 == 0) std::cout << "Количество букв четно\n";
    else std::cout << "Количество букв нечетно\n";
}
void task_6(){
    std::string secondname1;
    std::string secondname2;
    std::cout << "Введите две фамилии: ";
    std::cin >> secondname1;
    std::cin >> secondname2;
    if(length(secondname1) > length(secondname2)) std::cout << secondname1 << " длиннее "<< secondname2<<std::endl;
    else std::cout << secondname2 << " длиннее "<< secondname1<< std::endl;
}
void task_7(){
    std::string towns[3];
    int lengths[3] = {0, 0, 0};

    std::cout << "Введите название трех городов на латинице\n";

    for(int i{}; i < 3; ++i) std::cin >> towns[i];
    for(int i{}; i < 3; ++i) lengths[i] = length(towns[i]);
    int min_val = lengths[0];
    int max_val = lengths[1];
    int max_index = 0;
    int min_index = 1;
    for(int i{}; i < 3; ++i){
        if( lengths[i] > max_val){
            max_val = lengths[i];
            max_index = i;
        }else if(lengths[i] < min_val){
            min_val = lengths[i];
            min_index = i;
        }
    }
    std::cout << "Города с минимальной и максимальной длинной названия\n";
    std::cout << towns[min_index] << ' ' << towns[max_index] << '\n';
    

}
void task_8(){
    std::cout << "Введите слово и числа n и m\n";
    std::string str;
    std::string result_str;
    int m, n;
    std::cin >> str;
    std::cin >> m >> n;
    for(int i{m}; i <= n; ++i) result_str.push_back(str.at(i));
    std::cout << result_str <<std::endl;
}
void task_9(){
    std::cout << "Введите слово\n";
    std::string str;
    std::cin >> str;
    std::string result_str;
    for(int i{}; i < length(str); ++i) result_str.push_back('*');
    for(char i: str) result_str.push_back(i);
    for(int i{}; i < length(str); ++i) result_str.push_back('*');
    std::cout << result_str<<std::endl;

}
void task_10(){
    std::cout << "Введите слово\n";
    std::string str;
    std::cin >> str;

    int i{};
    int count{};
    while(str[i++] != '\0') if(str[i-1] == 'a') ++count;
    std::cout << "Процент букв а в слове = " << static_cast<float>(count)/length(str)*100 << "%\n";
}
void task_11(){
    std::string seq = "Can you can a can as a canner can can a can?";
    std::string new_word;

    std::cout << "Введите слово: ";
    std::cin >> new_word;
    std::string result_str;
    for(int i{}; i < seq.size(); ++i){
        if(seq[i] == 'c' && seq[i+1] =='a' && seq[i+2] == 'n'){
            for(char c:new_word) result_str.push_back(c);
            i += 2;
        }else result_str.push_back(seq[i]);
    }
    std::cout << result_str<<std::endl;

}