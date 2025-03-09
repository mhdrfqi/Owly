
# Owly - Advanced Dictionary Generator

Owly is a powerful **password generation tool** designed to create secure and diverse password lists for various purposes, including security audits, penetration testing, and password recovery. It combines **Leetspeak transformations**, **common password patterns**, and **user input variations** to generate up to **50,000 unique password combinations**. This tool is optimized for speed and is highly efficient, making it perfect for security professionals and ethical hackers who need large and varied password lists.

## Features

- **Generate 50,000 Passwords**: Create up to 50,000 unique password combinations with minimal effort.
- **Leetspeak Conversion**: Automatically transforms passwords into Leetspeak variations for added complexity.
- **Common Passwords**: Includes a list of common passwords used worldwide to generate realistic password combinations.
- **User Input Customization**: Allows the user to input personal data (e.g., name, birth year, special number) to generate tailored passwords.
- **Multi-threading**: Uses multi-threading to optimize performance and speed up password generation.
- **Safe File Writing**: Ensures that the wordlist is saved to a text file safely using thread synchronization.

## Why Owly?

Owly is ideal for professionals who need to test the strength of passwords or generate extensive password lists for security purposes. Whether you're conducting **penetration testing** or performing a **brute force attack**, Owly makes it easy to generate a wide variety of passwords, including the most commonly used ones, and test for vulnerabilities.

## Installation

Follow the steps below to set up and run Owly on your system.

### Requirements

- **Linux** (tested on Kali Linux)
- **G++ Compiler** (for compiling C++ code)
- **pthread** library (for multi-threading support)

### Steps to Install

1. **Clone the Repository**:
   Clone this repository to your local machine using the following command:
   ```bash
   git clone https://github.com/dannyk_739/Owly.git
   cd Owly
   ```

2. **Install Dependencies**:
   If you're using Kali Linux or Ubuntu, install the necessary libraries with:
   ```bash
   sudo apt update
   sudo apt install g++ libpthread-stubs0-dev
   ```

3. **Compile the Code**:
   Compile the C++ source code:
   ```bash
   g++ -std=c++11 Owly.cpp -o Owly -lpthread
   ```

4. **Run the Program**:
   After successful compilation, run the program:
   ```bash
   ./Owly
   ```

5. **Generate Passwords**:
   Follow the on-screen prompts to input your data and generate the password list. The generated passwords will be saved to `wordlist.txt`.

### Example Usage

```bash
Enter first name: john
Enter last name: doe
Enter birth year or special number: 1990
Enter a keyword (pet, favorite team, etc.): bulldog
Generating wordlist...
Thread 0 Progress: 10% done
Thread 0 Progress: 20% done
...
Wordlist saved to wordlist.txt successfully!
```

## File Structure

- `Owly.cpp`: Main source code of the password generator.
- `wordlist.txt`: Generated password list (output file).
- `README.md`: Documentation for the tool.

## Password Variations

Owly generates passwords based on:
- **Concatenation of user inputs** (e.g., `firstname + lastname`)
- **Leetspeak transformations** (e.g., `password` → `p@ssw0rd`)
- **Common password patterns** (e.g., `123456`, `qwerty`, `letmein`)
- **Random combinations of characters** to create a diverse set of passwords.

## Performance Optimization

Owly is optimized for **speed** and **efficiency**:
- **Multi-threading**: By utilizing multiple threads, Owly distributes the workload to speed up the generation process, reducing the time it takes to generate large password lists.
- **Efficient memory management**: The program ensures that it doesn’t consume excessive memory or resources, even when generating large numbers of passwords.

## Contributing

If you would like to contribute to this project, feel free to fork the repository, make your changes, and submit a pull request. Any improvements, bug fixes, or new features are welcome!

## License

Owly is licensed under the [MIT License](LICENSE).
