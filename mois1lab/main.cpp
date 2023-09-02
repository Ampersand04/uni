#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int vertices = 7;
    int edges = 12;

    vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));
    vector<pair<int, int>> edgeList = { {1,2},{1,3},{1,4},{1,6},{2,3},{2,4},{2,6},{2,7},{3,4},{4,5},{5,6},{6,7} };

    for (auto edge : edgeList) {
        int vertex1 = edge.first - 1;
        int vertex2 = edge.second - 1;
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;  // для неориентированного графа
    }

    cout << "Матрица смежности:" << endl;
    printMatrix(adjacencyMatrix);

    return 0;
}


/*
#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "rus");

    std::string sourceFilename = "file.txt";
    std::string destFilename = "file1.txt";

    std::ifstream sourceFile(sourceFilename);
    if (sourceFile.is_open()) {
        std::ofstream destFile(destFilename);

        if (destFile.is_open()) {
            std::string line;
            while (std::getline(sourceFile, line)) {
                destFile << line << std::endl;
            }
            destFile.close();
            sourceFile.close();
            std::cout << "Содержимое файла " << sourceFilename << " скопировано в файл " << destFilename << std::endl;
        }
        else {
            std::cout << "Не удалось создать файл " << destFilename << std::endl;
        }
    }
    else {
        std::cout << "Файл " << sourceFilename << " не найден." << std::endl;
    }

    return 0;
}
*/

/*
#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "rus");
    std::string filename = "file.txt";

    // Попытка открыть файл для чтения
    std::ifstream file(filename);

    if (file.is_open()) {
        // Файл существует, читаем из него и выводим содержимое
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        // Файл не существует, создаем его и записываем данные
        std::ofstream newFile(filename);
        if (newFile.is_open()) {
            newFile << "Пример текста для записи в файл." << std::endl;
            newFile.close();
            std::cout << "Файл создан: " << filename << std::endl;
        }
        else {
            std::cout << "Не удалось создать файл." << std::endl;
        }
    }

    return 0;
}
*/