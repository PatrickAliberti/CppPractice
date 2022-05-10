# CaesarsCipher

This program encrypts and de-encrypts the data stored in a binary file using dynamically allocated arrays of structures in C++.

Encrypt.cpp uses a dynamic array of structs to read data from a binary file and displays that data in the form of a table. The program uses an encryption key entered by the user to encrypt the binary data using a Caesar's cipher style encryption into a new array which gets displayed and written to a new file.

DeEncrypt.cpp reads the encrypted data into a dynamic array of structs and displays the information. The program uses the key to de-encrypt the data and read it into a new array, which gets displayed and written to a new binary file.

spy.dat is the binary file containing the origional un-encrypted file which should be passed in Encrypt.cpp as a test.

encryption is the binary file containing the de-encrypted data from the DeEncrypt.cpp program. You will have your own copy when you run DeEncrypt.cpp.
