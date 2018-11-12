int main() {
    double number;
    double* number_pointer = &number;
    double& number_ref = number;

    number = 3;          // Vanlig tilordning av verdi
    *number_pointer = 4; // Tilordne verdi til det pekeren peker på
    number_ref = 5;      // Tilordne verdi til det referansen refererer til
}
