#include <iostream>
#include <string>
#include <windows.h> 

bool tieneLlave = false;
bool tieneLinterna = false;
bool tieneDiario = false;
bool tieneDocumentos = false;

void mostrarMansion();
void mostrarLinterna();
void mostrarLlave();
void mostrarInventario();
void mostrarFinal(int tipoFinal);
void mostrarIntroduccion();

int obtenerDecision(int minOpcion, int maxOpcion);
void manejarEntradaPrincipal(); 
void explorarBiblioteca();
void volverConLlave();
void entrarPorPuerta();
void tocarTimbre();
void manejarExploracionPerimetro();
void continuarExplorandoJardin();
void manejarObjetoBrillante(bool& tieneLlave);
void explorarJardin(bool& tieneLlave);

void mostrarMansion() {
    std::cout << R"(
        /\                                                  /\
       /  \                                                /  \
      /    \                                              /    \
     /      \____________________________                /      \
    /       /                            \              /        \
   /       /                              \            /          \
  /       /                                \          /            \
 /       /                                  \________/              \
/       /                                                            \
|      /                                                              |
|     |                    MANSI�N BLACKWOOD                         |
|     |                                                              |
|     |                     ___________                              |
|     |                    |           |                             |
|     |                    |    ___    |                             |
|     |                    |   |   |   |                             |
|     |                    |   |   |   |                             |
|_____|____________________|___|___|___|_____________________________|
    )" << '\n';
}

void mostrarLinterna() {
    std::cout << R"(
     _______
    /       \
   /         \
   |  ====   |
   |         |
    \_______/
    )" << '\n';
}

void mostrarLlave() {
    std::cout << R"(
      .---.
     /    |\
     |    |/
     |    |
     |    |
     `    '
    )" << '\n';
}

void mostrarInventario() {
    std::cout << "\n=== INVENTARIO ===\n";
    if (tieneLlave) {
        std::cout << "- Llave antigua";
        mostrarLlave();
    }
    if (tieneLinterna) {
        std::cout << "- Linterna";
        mostrarLinterna();
    }
    if (tieneDiario) std::cout << "- Diario viejo\n";
    if (tieneDocumentos) std::cout << "- Documentos familiares\n";
    if (!tieneLlave && !tieneLinterna && !tieneDiario && !tieneDocumentos) {
        std::cout << "El inventario est� vac�o\n";
    }
    std::cout << "================\n\n";
}

void mostrarFinal(int tipoFinal) {
    std::cout << "\n=== FINAL ===\n";
    switch(tipoFinal) {
        case 1:
            std::cout << "FINAL: EL HEREDERO LEG�TIMO\n";
            std::cout << "Despu�s de descubrir los documentos que prueban tu linaje,\n";
            std::cout << "te conviertes en el leg�timo heredero de la mansi�n Blackwood.\n";
            break;
        case 2:
            std::cout << "FINAL: LA MALDICI�N\n";
            std::cout << "Descubres que la familia est� maldita. Debes decidir entre\n";
            std::cout << "aceptar la fortuna y la maldici�n, o abandonarlo todo.\n";
            break;
        case 3:
            std::cout << "FINAL: EL SECRETO OSCURO\n";
            std::cout << "Los documentos revelan que la fortuna familiar proviene de\n";
            std::cout << "actividades ilegales. �Expondr�s la verdad o mantendr�s el secreto?\n";
            break;
        default:
            std::cout << "Te alejas de la mansi�n, dejando sus secretos sin resolver...\n";
    }
}


//Validacion para obtener una decision
int obtenerDecision(int minOpcion, int maxOpcion) {
    int decision;
    do {
        std::cin >> decision;
        if(decision < minOpcion || decision > maxOpcion) std::cout << "Ingrese un n�mero v�lido!\n";
    } while (decision < minOpcion || decision > maxOpcion);
    return decision;
}


void explorarBiblioteca() {
    std::cout << "\nEntras en la biblioteca polvorienta...\n";
    if (!tieneLinterna) {
        std::cout << "Est� demasiado oscuro para ver algo con claridad.\n";
        std::cout << "Quiz�s necesites encontrar una forma de iluminar el lugar.\n";
    } else {
        std::cout << "Con la linterna, puedes ver claramente los antiguos estantes.\n";
        tieneDiario = true;
        std::cout << "�Has encontrado un diario viejo!\n";
        mostrarInventario();
    }
}

//Menu Principal
void mostrarIntroduccion() {
    std::cout << "El Misterio de la Mansi�n Blackwood\n\n";
    std::cout << "Recibes una carta misteriosa que te invita a la Mansi�n Blackwood, una propiedad antigua y remota.\n";
    std::cout << "La carta menciona que podr�as ser el heredero de una gran fortuna, pero para reclamarla, debes pasar una noche en la mansion y descubrir el secreto que esconde la familia Blackwood.\n";
}

void volverConLlave() {
    std::cout << "\nDecides volver a la entrada principal, esta vez con la llave en tu poder.\n";
    std::cout << "Al llegar, notas que adem�s de la puerta principal, hay un peque�o buz�n que tambi�n tiene una cerradura.\n";
    
    int decision;
    std::cout << "\n�D�nde decides usar la llave?\n";
    std::cout << "1. Probar la llave en la puerta principal\n";
    std::cout << "2. Intentar abrir el buz�n\n";
    decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        std::cout << "\nLa llave encaja perfectamente. Al entrar, encuentras documentos importantes...\n";
        tieneDocumentos = true;
        mostrarInventario();
        mostrarFinal(1); // Final del heredero leg�timo
    } else {
        std::cout << "\nEn el buz�n encuentras documentos inquietantes sobre la familia...\n";
        tieneDocumentos = true;
        mostrarInventario();
        mostrarFinal(3); // Final del secreto oscuro
    }
}

void entrarPorPuerta() {
    std::cout << "\nEmpujas suavemente la puerta. Esta se abre con un chirrido.\n";
    std::cout << "El vest�bulo est� oscuro, pero alcanzas a ver una luz tenue que viene del segundo piso.\n";
    tieneLinterna = true; // Encuentras una linterna en una mesa cercana
    std::cout << "\n�Has encontrado una linterna en una mesa cercana!\n";
    mostrarLinterna();
    mostrarInventario();
    
    explorarBiblioteca();
}

void tocarTimbre() {
    std::cout << "\nDecides ser cort�s y tocas el timbre. El sonido reverbera por toda la casa...\n";
    std::cout << "Despu�s de unos momentos, escuchas pasos acerc�ndose a la puerta.\n";
    
    int decision;
    std::cout << "\nLos pasos se detienen frente a la puerta. Una voz anciana pregunta: '�Qui�n es?'\n";
    std::cout << "1. Mencionar la carta de invitaci�n\n";
    std::cout << "2. Presentarte como un familiar lejano\n";
    decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        std::cout << "\nLa puerta se abre. Una anciana te recibe con una sonrisa conocedora...\n";
        tieneDocumentos = true;
        mostrarFinal(1); // Final del heredero leg�timo
    } else {
        std::cout << "\nLa anciana parece sospechar. Te entrega unos documentos inquietantes...\n";
        tieneDocumentos = true;
        mostrarFinal(3); // Final del secreto oscuro
    }
}


void manejarExploracionPerimetro() {
    std::cout << "\nDecides continuar tu exploraci�n y encuentras una ventana rota en la parte trasera.\n";
    std::cout << "Parece lo suficientemente grande para que alguien pueda entrar...\n";
    
    int decision = obtenerDecision(1, 2);
    std::cout << "\n�Qu� decides hacer con la ventana rota?\n";
    std::cout << "1. Intentar entrar por la ventana\n";
    std::cout << "2. Buscar otra entrada menos peligrosa\n";
    
    if (decision == 1) {
        // Posible final tr�gico o descubrimiento importante
        mostrarFinal(3);
    } else {
        // Volver a la entrada principal
        manejarEntradaPrincipal();
    }
}

void continuarExplorandoJardin() {
    std::cout << "\nDecides continuar explorando el jard�n. Entre la maleza,\n";
    std::cout << "descubres un viejo invernadero con plantas extra�as en su interior.\n";
    
    int decision;
    std::cout << "\n�Qu� haces?\n";
    std::cout << "1. Intentar entrar al invernadero\n";
    std::cout << "2. Regresar a la entrada principal\n";
    decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        std::cout << "\nDentro del invernadero, encuentras plantas m�sticas y un antiguo grimorio...\n";
        mostrarFinal(2); // Final de la maldici�n
    } else {
        manejarEntradaPrincipal();
    }
}

// Funci�n para manejar la entrada principal
void manejarEntradaPrincipal() {
    int decision;
    std::cout << "\nDecides ser directo y caminas hacia la puerta principal.\n";
    std::cout << "Al acercarte, notas que la puerta est� ligeramente entreabierta.\n";
    
    std::cout << "\n�Qu� haces?\n";
    std::cout << "1. Empujar la puerta y entrar\n";
    std::cout << "2. Tocar el timbre primero\n";
    decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        entrarPorPuerta();
    } else {
        tocarTimbre();
    }
}

void manejarObjetoBrillante(bool& tieneLlave) {
    int decision;
    tieneLlave = true;
    std::cout << "\nTe acercas y encuentras una llave antigua entre las hierbas.\n";
    mostrarLlave();
    std::cout << "Podr�a ser �til m�s adelante...\n";
    mostrarInventario();
    
    std::cout << "\n�Qu� haces ahora?\n";
    std::cout << "1. Volver a la entrada principal con la llave\n";
    std::cout << "2. Seguir explorando el jard�n\n";
    decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        volverConLlave();
    } else {
        continuarExplorandoJardin();
    }
}

// Funci�n para manejar la exploraci�n del jard�n
void explorarJardin(bool& tieneLlave) {
    int decision;
    std::cout << "\nDecides ser cauteloso y examinar los alrededores primero.\n";
    std::cout << "Mientras caminas alrededor de la mansi�n, encuentras un jard�n descuidado.\n";
    std::cout << "Entre las hierbas altas, algo met�lico brilla.\n";
    
    std::cout << "\n�Qu� haces?\n";
    std::cout << "1. Investigar el objeto brillante\n";
    std::cout << "2. Seguir explorando el per�metro\n";
    decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        manejarObjetoBrillante(tieneLlave);
    } else {
        manejarExploracionPerimetro();
    }
}

int main() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);    
    mostrarMansion();
    mostrarIntroduccion();
    mostrarInventario();
    
    std::cout << "Te encuentras frente a la mansi�n. �Qu� decides hacer?\n";
    std::cout << "1. Entrar por la puerta principal\n";
    std::cout << "2. Investigar alrededor de la casa primero\n";
    
    int decision = obtenerDecision(1, 2);
    
    if (decision == 1) {
        manejarEntradaPrincipal();
    } else {
        explorarJardin(tieneLlave);
    }
    
    return 0;
}
