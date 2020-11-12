//Librerias necesarias
#include <iostream>
#include <vector>

//Libreria para generar distintos seeds para rand()
#include <ctime>

//Librerias para el tiempo
#include <chrono>
#include <thread>

//Namespaces
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main()
{
	//Generamos los distintos seeds para el tiempo
	srand(time(0));

	//Declaramos el número máximo de items que puede tener y generar el inventario
	int inventorySpaceGenerate = 7;
	int inventorySpaceMax = 20;

	//Declarar el numero de elementos que el generador puede generar
	int inventorySpaceOccGen = 0;

	int inventorySpaceOccPick = 0;

	//Se crea el vector inventory
	vector<string> inventory;

	//Se crean los vectores que mantienen los la hierba mala y gusano dorado
	const vector<string> generate
	{
		"Hierba Mala (HM)", "Gusano Dorado (GD)", "Hierba Mala (HM)", "Gusano Dorado (GD)", "Hierba Mala (HM)", "Gusano Dorado (GD)", "Hierba Mala (HM)", "Gusano Dorado (GD)", "Hierba Mala (HM)", "Gusano Dorado (GD)",
	};

	//Se crean los vectores que mantienen las rocas
	const vector<string> pickup
	{
		"Roca Blanda", "Roca Dura", "Roca Cristalina", "Roca Magica"
	};


	//Creamos la variable para la userInput
	string userInput = "N/A";

	//Creamos las variables para almacenar la posicion de los elementos aleatorios dentro de "generate"
	int randomGenerate;

	//Creamos las variables para el máximo y mínimo de los valores random
	const int generateMin = 0;
	const int generateMax = generate.size() - 1;

	//Creamos las variables para almacenar la posicion de los elementos aleatorios dentro de "pickup"
	int randomPickup;

	//Creamos las variables para el máximo y mínimo de los valores random
	const int pickupMin = 0;
	const int pickupMax = pickup.size() - 1;

	//Se programa el emulador de "generando..."
	while (userInput != "exit" && userInput != "0")
	{
		//Se crea el menú para el usuario
		cout << "Presiona las teclas:" << "\n";
		cout << "g. Generar inventario" << endl;
		cout << "h. Recoger roca" << endl;
		cout << "i. Revisar inventario" << endl;
		cout << "0. Salir" << endl;

		cout << "=========================================" << endl;
		cout << "Entrada de usuario: ";
		cin >> userInput;

		//Si el usuario escribe G
		if (userInput == "g" || userInput == "G")
		{
			system("CLS");

			//Verificamos si se puede generar inventario. Se puede generar cuando el generador no haya obtenido 7 objetos.
			if (inventorySpaceOccGen < inventorySpaceGenerate)
			{
				//Se usan las librerías chrono y thread para hacer el temporizador de un segundo de generacion.
				cout << "Generando.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				//Se genera una posición aleatoria dentro de generate
				randomGenerate = rand() % (generateMax - generateMin + 1) + generateMin;

				//Se le informa al usuario lo que se obtuvo al generar.
				cout << "Obtuviste " << generate[randomGenerate] << endl;
				cout << endl;
				inventorySpaceOccGen++;

				//Se agrega el objeto obtenido al inventario
				inventory.push_back(generate[randomGenerate]);

				//Se le informa al usuario los espacios restantes para minerales
				cout << "Solo puedes generar " << inventorySpaceGenerate - inventorySpaceOccGen << " objetos mas." << "\n";


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

		//Si el usuario escribe I
		else if (userInput == "i" || userInput == "I")
		{
			system("CLS");

			//Se usa la librería chrono y thread para hacer el segundo de conteo para la apertura del inventario
			cout << "Abriendo inventario.";
			sleep_for(milliseconds(500));
			cout << ".";
			sleep_for(milliseconds(500));
			cout << "." << endl;

			//Se verifica si el inventario está vacío
			if (inventorySpaceGenerate == 0)
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

		//Si el usuario escribe H
		else if (userInput == "h" || userInput == "H")
		{
			system("CLS");

			cout << "Escoja una roca:" << "\n";
			cout << "g. Roca blanda" << endl;
			cout << "h. Roca dura" << endl;
			cout << "i. Roca cristalina" << endl;
			cout << "p. Roca magica" << endl;

			cout << "=========================================" << endl;
			cout << "Entrada de usuario: ";
			cin >> userInput;

			if (userInput == "g" || userInput == "G")
			{
				//Se usan las librerias chrono y thread para hacer el temporizador de un segundo de recogida.
				cout << "Recogiendo.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				randomPickup = rand() % 100 + 1;

				if (randomPickup <= 75)
				{
					cout << "Recoleccion exitosa!" << endl;
					inventorySpaceOccPick++;

					inventory.push_back(pickup[0]);
				}
				else
				{
					cout << "La roca fue destruida" << endl;
				}
				system("pause");
				system("CLS");
			}

			if (userInput == "h" || userInput == "H")
			{
				//Se usan las librerias chrono y thread para hacer el temporizador de un segundo de recogida.
				cout << "Recogiendo.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				randomPickup = rand() % 100 + 1;

				if (randomPickup <= 75)
				{
					cout << "Recoleccion exitosa!" << endl;
					inventorySpaceOccPick++;

					inventory.push_back(pickup[1]);
				}
				else
				{
					cout << "La roca fue destruida" << endl;
				}
				system("pause");
				system("CLS");
			}

			if (userInput == "i" || userInput == "I")
			{
				//Se usan las librerias chrono y thread para hacer el temporizador de un segundo de recogida.
				cout << "Recogiendo.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				randomPickup = rand() % 100 + 1;

				if (randomPickup <= 75)
				{
					cout << "Recoleccion exitosa!" << endl;
					inventorySpaceOccPick++;

					inventory.push_back(pickup[2]);
				}
				else
				{
					cout << "La roca fue destruida" << endl;
				}
				system("pause");
				system("CLS");
			}

			if (userInput == "p" || userInput == "P")
			{
				//Se usan las librerias chrono y thread para hacer el temporizador de un segundo de recogida.
				cout << "Recogiendo.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				randomPickup = rand() % 100 + 1;

				if (randomPickup <= 50)
				{
					cout << "Recoleccion exitosa!" << endl;
					inventorySpaceOccPick++;

					inventory.push_back(pickup[3]);
				}
				else
				{
					cout << "La roca fue destruida" << endl;
				}
				system("pause");
				system("CLS");
			}

			/*if (inventorySpaceOccLeaf < inventorySpaceLeaves)
			{
				//Se usan las librerias chrono y thread para hacer el temporizador de un segundo de recogida.
				cout << "Recogiendo.";
				sleep_for(milliseconds(500));
				cout << ".";
				sleep_for(milliseconds(500));
				cout << "." << endl;

				//Se genera una posicion aleatoria dentro de leaves
				randomLeavesPos = rand() & (leavesMax - leavesMin + 1) + leavesMin;

				//Se le informa al usuario la hoja que se recogio
				//cout << "Obtuviste " << leaves[randomLeavesPos] << endl;
				cout << endl;
				inventorySpaceOccLeaf++;

				//Se agrega la hoja recogida al inventario
				//inventory.push_back(leaves[randomLeavesPos]);

				//Se le informa al usuario los espacios restantes en los inventarios
				cout << "Te quedan " << inventorySpaceLeaves - inventorySpaceOccLeaf << " espacios disponibles para hojas y " << inventorySpaceMinerals - inventorySpaceOccMin << " espacios para minerales en el inventario." << endl;

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
		}*/
			cout << "\n\n";
		}
	}
}
