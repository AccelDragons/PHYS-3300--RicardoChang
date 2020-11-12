//Libraries
#include <iostream>
#include <vector>

//Library to generate distinct seeds for rand()
#include <ctime>

//Libraries for time
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main()
{
	//Generate different seeds
	srand(time(0));

	//Declare maximum number of items that inventoryDeclare can have
	int inventorySpaceMinerals = 3;

	//Declare the maximum number of leaves that inventoryDeclare can have
	int inventorySpaceLeaves = 5;

	//Declare the number of minerales and leaves that are in the inventory
	int inventorySpaceMinMax = 0;
	int inventorySpaceLeafMax = 0;

	//inventory vector
	vector<string> inventory;

	//Vectors that hold the crystals and leaves
	const vector<string> minerals
	{
		"Cristal Azul (A)", "Cristal Verde (V)"
	};

	const vector<string> leaves
	{
		"Verila Pluma (VP)", "Secta Doralis (SD)", "Crystalia Fulminis (CF)"
	};

	//Variable for userInput
	string userInput = "N/A";

	//Variables for random positions of the leaves and minerals
	int randomMineralPos;
	int randomLeavesPos;

	//Variables for Maximum and Minimum random values
	const int mineralsMin = 0;
	const int mineralsMax = minerals.size() - 1;

	const int leavesMin = 0;
	const int leavesMax = leaves.size() - 1;

	//Se programa el emulador de "minando..."
	while (userInput != "exit" && userInput != "0")
	{
		//Se crea el menú para el usuario
		cout << "Presiona una de las teclas:" << "\n";
		cout << "q. Revisar inventario" << endl;
		cout << "w. Obtener hojas" << endl;
		cout << "e. Obtener minerales" << endl;
		cout << "0. Salir" << endl;
		//Espacio
		cout << "=========================================" << endl;
		cout << "Entrada de usuario: ";
		cin >> userInput;

		//Si el usuario escribe Q
		if (userInput == "q" || userInput == "Q")
		{
			system("CLS");

			//Se usa la librería chrono y thread para hacer el segundo de conteo para la apertura del inventario
			cout << "Abriendo inventario.";
			sleep_for(milliseconds(500));
			cout << ".";
			sleep_for(milliseconds(500));
			cout << "." << endl;

			//Se verifica si el inventario está vacío
			if (inventorySpaceMinerals == 0 && inventorySpaceLeaves == 0)
			{
				cout << "INVENTARIO VACIO!!" << endl;
				sleep_for(seconds(1));
				system("pause");
				system("CLS");
			}
			else
			{
				for (int i = 0; i < inventory.size(); i++)
				{
					cout << inventory[i] << "\n";
				}
			}
		}

		//Si el usuario escribe W
		else if (userInput == "w" || userInput == "W")
		{
			system("CLS");

			//Como solo se puede agregar minerales cuando su parte del inventario tiene espacio, verificamos si tiene espacio o no.
			if (inventorySpaceMinMax < inventorySpaceMinerals)
			{
				//Se usan las librerías chrono y thread para hacer el temporizador de un segundo de minado.
				cout << "Minando.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				//Se genera una posición aleatoria dentro de minerals
				randomMineralPos = rand() % (mineralsMax - mineralsMin + 1) + mineralsMin;

				//Se le informa al usuario el mineral que se obtuvo al minar
				cout << "Obtuviste " << minerals[randomMineralPos] << endl;
				cout << endl;
				inventorySpaceMinMax++;

				//Se agrega el mineral obtenido al inventario
				inventory.push_back(minerals[randomMineralPos]);

				//Se le informa al usuario los espacios restantes para minerales
				cout << "Te quedan " << inventorySpaceMinerals - inventorySpaceMinMax << " espacios disponibles para minerales y " << inventorySpaceLeaves - inventorySpaceLeafMax << " espacios para hojas en el inventario." << endl;

				system("pause");
				system("CLS");
			}
			else
			{
				system("CLS");
				cout << "INVENTARIO LLENO!!" << endl;
				sleep_for(seconds(2));
				system("pause");
				system("CLS");
			}
		}

		//Si el usuario escribe E
		else if (userInput == "e" || userInput == "E")
		{
			//Clears screen
			system("CLS");

			if (inventorySpaceLeafMax < inventorySpaceLeaves)
			{
				//Se usan las librerias chrono y thread para hacer el temporizador de un segundo de recogida.
				cout << "Recogiendo. ";
				sleep_for(milliseconds(500));
				cout << ". ";
				sleep_for(milliseconds(500));
				cout << ". " << endl;

				//Se genera una posicion aleatoria dentro de leaves
				randomLeavesPos = rand() % (leavesMax - leavesMin + 1) + leavesMin;

				//Se le informa al usuario la hoja que se recogio
				cout << "Obtuviste " << leaves[randomLeavesPos] << endl;
				cout << endl;
				inventorySpaceLeafMax++;

				//Se agrega la hoja recogida al inventario
				inventory.push_back(leaves[randomLeavesPos]);

				//Se le informa al usuario los espacios restantes en los inventarios
				cout << "Te quedan " << inventorySpaceLeaves - inventorySpaceLeafMax << " espacios disponibles para hojas y " << inventorySpaceMinerals - inventorySpaceMinMax << " espacios para minerales en el inventario." << endl;

				system("pause");
				system("CLS");
			}
		}
		cout << "\n\n";
	}

}
