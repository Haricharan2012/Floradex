🌿 Floradex – An Interactive Plant Encyclopedia

Floradex is an interactive digital plant encyclopedia designed to make botanical learning engaging and immersive. Inspired by the Pokédex, this application provides a visually appealing and intuitive platform to explore wild plants. Built using the Raylib framework, it ensures a smooth user experience with an interactive UI and efficient data management.
🚀 Features

✅ Point-and-Click Interface: Navigate using the mouse—no arrow keys required!<br>
✅ Interactive Plant Encyclopedia: Explore different plant species with images, details, and habitat descriptions.<br>
✅ Linear Search Algorithm: Find specific plants efficiently using a linear search.<br>
✅ Stack-Based Data Handling: Uses a stack to manage the plant info screens efficiently.<br>
✅ Graphical UI with Raylib: Modern, responsive UI with textures, animations, and interactive elements.<br>
✅ Collection Feature: Add plants to your collection and revisit them anytime.<br>
✅ Optimized for Performance: Implements collision detection and optimized event handling for smooth performance.<br>
✅ Time & Space Efficiency: Designed with O(f × n) time complexity and O(1) space complexity.<br>
📸 Screenshots


🛠️ Tech Stack

    Programming Language: C
    Graphics Library: Raylib
    Data Structures: Arrays & Stack
    Search Algorithm: Linear Search

🏗️ Getting Started

1️⃣ Clone the Repository

    git clone https://github.com/your-username/floradex.git
    cd floradex

2️⃣ Install Dependencies

Ensure you have Raylib installed:

    sudo apt install libraylib-dev  # (Linux)
    brew install raylib             # (Mac)

For Windows, download Raylib from raylib.com and set up your compiler.\

3️⃣ Compile and Run

    gcc traywinui.c -o result -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    ./result

🎮 Controls

    Mouse Click: Select plant entries, navigate UI
    Right Click: View detailed plant information
    Keyboard (if applicable): Additional shortcuts for power users

🔍 Search Algorithm

Floradex uses a linear search to locate specific plants in the collection. This ensures simplicity and ease of implementation while allowing users to efficiently find plant data.
⏳ Time & Space Complexity

    Time Complexity:
        Main Loop: O(f × n), where f is the number of frames, and n is the number of UI elements processed per frame.
        Linear Search: O(n), since it iterates through the list of plants sequentially.

    Space Complexity: O(1), as all data structures (arrays & stack) have fixed sizes with no dynamic allocation.

👨‍💻 Contributions

Contributions are welcome! Feel free to fork the repository and submit a pull request.

📜 License


This project is licensed under the MIT License.




https://github.com/user-attachments/assets/e0739c07-5937-4880-8825-f8965968100f




