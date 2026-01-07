# Stock-Inventory-System

## Features

* **Role-Based Access Control:**
    * **Manager/Owner:** Full access to add, edit, and view stock, plus administrative settings.
    * **Employee:** Read-only access to view stock.
* **Data Persistence:** Uses file handling (`data.txt`, `owner.txt`) to save records between sessions.
* **Stock Management:**
    * Add new items (ID, Name, Quantity, Price).
    * Automatically calculates total value.
    * Edit existing stock items.
* **Security:** Password-protected owner dashboard.

## Installation & Usage

### Prerequisites
* A C++ Compiler (G++, Clang, or MSVC)

### How to Run

1.  **Clone the repository**
    ```bash
    git clone [https://github.com/M-Talha-Imran0/Stock-Inventory-System.git](https://github.com/M-Talha-Imran0/Stock-Inventory-System.git)
    cd Stock-Inventory-System
    ```

2.  **Compile the code**
    ```bash
    g++ main.cpp -o inventory_app
    ```

3.  **Run the application**
    * On Windows:
        ```bash
        inventory_app.exe
        ```
    * On Linux/Mac:
        ```bash
        ./inventory_app
        ```

## File Structure

* `main.cpp`: The source code.
* `data.txt`: Stores the inventory data (ID, Name, Quantity, Price, Total).
* `owner.txt`: Stores the owner's credentials (Name on line 1, Password on line 2).

## Default Credentials

To log in as the **Manager**, ensure `owner.txt` exists. The default setup provided in this repo uses:

* **Name:** `admin`
* **Password:** `admin123`

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
