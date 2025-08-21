 # 🎴 Embaucado - Proyecto Final de Programación I

## 📝 Introducción
Este proyecto es la implementación en C++ del juego de cartas "Embaucado".  
El juego se ejecuta en modo consola y utiliza la biblioteca `rlutil` para gestionar colores, posicionamiento del cursor y otras utilidades visuales.  

## 🎯 Reglas del juego
### 🏆 Objetivo

Ganar más puntos que el rival tras 3 rondas.
Cada jugador recibe 5 cartas y una carta embaucadora define qué palos no suman puntos.

### 🃏 Cartas
- **Baraja francesa usada:** 10, J, Q, K, A de Corazones, Diamantes, Picas y Tréboles (20 cartas).  
- **Mazo de figuras:** 4 cartas (Corazón, Diamante, Pica, Trébol).  
- **Valores de cartas:**
  - 10 = 10 puntos
  - J = 11 puntos
  - Q = 12 puntos
  - K = 15 puntos
  - A = 20 puntos

### ⚔️ Desarrollo
1. Se juega en tres rondas.
2. Cada jugador recibe su mano de 5 cartas y se revela la carta embaucadora.
3. Las cartas del mismo palo que la embaucadora no suman puntos.
4. En rondas 2 y 3, un jugador puede sacrificar 20 puntos para cambiar la carta embaucadora.
5. Se suman los puntos no embaucados para determinar el ganador de la ronda.

### 🥇 Ganador
- Quien tenga más puntos tras las tres rondas.
- En caso de empate: gana quien obtuvo la mayor cantidad de puntos en alguna ronda.
- Si persiste el empate: el juego termina en empate.

## ✨ Features (Características)
- **Interfaz en consola**: Utiliza `rlutil` para colores y posicionamiento de texto.
- **Menú interactivo**: Permite a los jugadores escoger entre jugar, ver estadísticas o ver créditos.
- **Lógica del juego**: Reparto de cartas, cálculo de puntajes y verificación de acciones especiales.
- **Estadísticas**: Registro del jugador con mayor puntaje y resolución de empates.
- **Créditos**: Información y agradecimientos al desarrollador y bibliotecas utilizadas.
- **Diseño modular educativo**: Facilita la comprensión de conceptos de C++ y programación estructurada.

## 💻 Requirements (Requisitos)
- **Compilador de C++** (g++, MSVC, etc.)
- **Biblioteca rlutil**
- **Sistema operativo**: Windows o Linux
- **Entorno de desarrollo opcional**: Code::Blocks (`Cartas.cbp` incluido)

## 🛠 Installation (Instalación)
1. ### Clonar el repositorio
   Clona el repositorio en tu máquina local utilizando git:  
  
   ```git clone https://github.com/npmucci/Proyecto_Final_ProgramacionI.git```
  
2. **Abrir el proyecto**  
   Utiliza Code::Blocks o tu entorno de desarrollo preferido y abre el archivo del proyecto “Cartas.cbp”.
3. **Configurar el compilador**  
   Asegúrate de que el compilador de C++ se encuentre correctamente configurado en tu entorno. Si usas g++, configura las opciones de compilación para incluir banderas como ```-Wall -fexceptions```

## 🎮 Usage (Uso)
1. **Compilar el proyecto**  
   Una vez abierto el proyecto en el entorno seleccionado, compílalo para generar el ejecutable.

2. **Ejecutar el juego**  
   Ejecuta el archivo generado (por ejemplo, `Cartas`) desde la terminal o desde el mismo entorno de desarrollo.

3. **Navegar por el menú**  
   Al iniciar, se desplegará un menú interactivo con las siguientes opciones:  
   - **JUGAR**: Inicia la partida.  
   - **ESTADÍSTICAS**: Muestra la información del mejor jugador y sus puntajes.  
   - **CRÉDITOS**: Muestra la sección de créditos y agradecimientos.  
   - **SALIR**: Finaliza el juego.

4. **Interacción en el juego**  
   Sigue las indicaciones en pantalla. Durante la partida, se realizarán los repartos de cartas y se solicitarán confirmaciones para acciones especiales, como el cambio de carta embaucadora.

## ⚙️ Configuration (Configuración)
- **Parámetros del juego**:  
  - La cantidad de rondas y jugadores está definida en constantes en `jugar.cpp` (por ejemplo, `CANT_RONDAS` y `CANT_JUGADORES`).  
  - El costo por cambiar la carta embaucadora está establecido (típicamente 20 puntos) y puede modificarse en el mismo código.

- **Personalización visual**:  
  - Los colores y estilos de visualización dependen de la configuración de la biblioteca `rlutil`.  
  - Se pueden ajustar en `rlutil.h` o mediante llamadas a funciones como `rlutil::setColor`.

- **Ajustes de entrada y respuesta**:  
  - La función `manejarRespuesta` en `jugar.cpp` gestiona las entradas de los usuarios y puede ser modificada según sea necesario para adaptarse a otras teclas o condiciones.

  ## 👩‍💻 Créditos

- **Desarrollador:** Natalia Mucci  
- **Bibliotecas utilizadas:**  
  - [rlutil](https://github.com/tapio/rlutil) para colores y manejo de consola  

## 📝 Licencia

Este proyecto está bajo la licencia **MIT**.

- Permite uso, copia, modificación y distribución del software de manera gratuita.  
- No ofrece garantía sobre el software.  
- Debe incluirse el aviso de copyright y la licencia en todas las copias o partes significativas del software.

