/* data types in C:
 * char a = 'C';                // single characters
 * char b[] = "Bro"             // array of characters (string)
 * float c = 3.14159265         // 4 bytes (32 bit of precision) 6 - 7 digits %f
 * double d = 3.14159265        // 8 bytes (64 bit of precision) 15 - 16 digits
 *                              // %lf
 * bool e = true                // 1 byte (true or false) %d (#include
 *                              // <stdbool.h>)
 * char f = 100                 // 1 byte (-128 to +127) %d or %c
 * unsigned char g = 255        // 1 byte (0 to +255) %d or %c
 * short int h = 32767          // 2 bytes (-32,768 to +32,767) %d
 * unsigned short int i = 65535 // 2 bytes (0 to +65,535) %d
 * int j = 2147483647           // 4 bytes (-2,147,483,648 to +2,147,438,647) %d
 *                              // ints are already considered long int,
 *                              // not to be confused with the syntax
 * unsigned int k = 4294967295L // 4 bytes (0 to +4,294,967,295) %u
 * long long int l = 9223372036854775807
 *                              // 8 bytes (-9 quintillion to
 *                              // +9 quintillion) %lld
 * long long unsigned int m = 18446744973709551615
 *                              // 8 bytes (0 to
 *                              // +18 quintillion) %llu
 */
