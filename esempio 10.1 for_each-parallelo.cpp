#include <iostream>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <algorithm>
#include <execution>      // std::execution::par
void HTTPGetRequest(const std::string& url)
{
    std::cout << "GET request: " << url << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

/*
codice valido solo dalla versione c++17
libreria: execution
*/
int main() {
    std::vector<std::string> urls = {
        "URL_1",
        "URL_2",
        "URL_3",
        "URL_4",
        "URL_5",
        "URL_6",
    };
    std::cout << "Sequencial execution:\n";
    std::for_each(urls.begin(), urls.end(), HTTPGetRequest);
    
    std::cout << "Parallel execution:\n";
    std::for_each(std::execution::par, urls.begin(), urls.end(), HTTPGetRequest);
    return 0;
}
