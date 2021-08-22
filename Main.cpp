#include <iostream>
#include <fstream>
#include <chrono>

#include "sha256.h"
#include "md5.h"
#include "sha1.h"

std::string get_hash_type(int index, std::string in) {
	if (index == 0 || index == 5)
		return sha256(in);

	else if (index == 1)
		return md5(in);

	else if (index == 2)
		return(sha1(in));
	
}

int main() {
	while (true) {
		std::ofstream out;
		std::string in;
		int hash = 5;
		std::cout << "Welcome to hash cracker, please enter the type of hash you would like to cracked using the brute force method. Enter --help for information about the general usage and the supported hashes.\n";
		std::cin >> in;

		bool repeat = true;

		while (repeat == true) {
			if (in == "sha256") {
				hash = 0;
				repeat = false;
				break;
			}
			else if (in == "md5") {
				hash = 1;
				repeat = false;
				break;
			}
			else if (in == "sha1") {
				hash = 2;
				repeat = false;
				break;
			}
			else {
				hash = 5;
				repeat = true;
			}
			if (in == "--help") {
				std::cout << "\nWelcome to hash cracker! In this application, using the brute force method, you will get the value of the hash based on what you input. Make sure the letters in your hash are all lowercase, otherwise it may not work. The hash types we support are are md5, sha256, and sha1. Please follow all the instructions given and you will get a result based off your hash. \n\n";
				repeat = true;
			}

			std::cout << "Please enter the type of hash you would like to cracked using the brute force method. Make sure all the letter in your hash are lowercase. Please enter --help for general usage and the supported hashes.\n";
			std::cin >> in;
		}

		std::cout << "\nPlease enter your hash now. \n";
		std::cin >> in;

		std::cout << "\n\nYour hash is being craked. You can find a log of this hash in the log folder. This may take hours depending on how long the string is, so please be patient. Please note that if the original text is longer than 8 characters, it will not be able to process it.\n\n";

		bool isFound = false;
		std::string arr[] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9"};
		out.open("Log\\" + in + ".txt", std::ios_base::app);

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point end;

		for (int i = 0; i < 62; i++) {
			//std::cout << sha256(arr[i]) << std::endl;
			if (get_hash_type(hash, arr[i]) == in) {
				isFound = true;
				std::cout << "The hash is equal to : " + arr[i] << std::endl;
				out << "Hash : " + in + "\n";
				out << "Original Text : " + (arr[i]) + "\n";

				if (hash == 0 || hash == 5)
					out << "Hash Type : sha256\n";

				else if (hash == 1)
					out << "Hash Type : md5\n";

				else if (hash == 2)
					out << "Hash Type : sha1\n";

				end = std::chrono::steady_clock::now();
				if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
					out << "Time taken : Less than a minute...\n";
				else
					out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

				out.close();
				break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					if (get_hash_type(hash, arr[i] + arr[ie]) == in) {
						isFound = true;
						std::cout << "The hash is equal to : " + (arr[i] + arr[ie]) << std::endl;

						out << "Hash : " + in + "\n";
						out << "Original Text : " + (arr[i] + arr[ie]) + "\n";

						if (hash == 0 || hash == 5)
							out << "Hash Type : sha256\n";

						else if (hash == 1)
							out << "Hash Type : md5\n";

						else if (hash == 2)
							out << "Hash Type : sha1\n";

						end = std::chrono::steady_clock::now();
						if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
							out << "Time taken : Less than a minute...\n";
						else
							out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

						out.close();
						break;
					}
				}

				if (isFound == true)
					break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					for (int iea = 0; iea < 62; iea++) {
						if (get_hash_type(hash, arr[i] + arr[ie] + arr[iea]) == in) {
							isFound = true;
							std::cout << "The hash is equal to : " + (arr[i] + arr[ie] + arr[iea]) << std::endl;

							out << "Hash : " + in + "\n";
							out << "Original Text : " + (arr[i] + arr[ie] + arr[iea]) + "\n";

							if (hash == 0 || hash == 5)
								out << "Hash Type : sha256\n";

							else if (hash == 1)
								out << "Hash Type : md5\n";

							else if (hash == 2)
								out << "Hash Type : sha1\n";

							end = std::chrono::steady_clock::now();
							if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
								out << "Time taken : Less than a minute...\n";
							else
								out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

							out.close();
							break;
						}
					}

					if (isFound == true)
						break;
				}

				if (isFound == true)
					break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					for (int iea = 0; iea < 62; iea++) {
						for (int ieac = 0; ieac < 62; ieac++) {
							if (get_hash_type(hash, arr[i] + arr[ie] + arr[iea] + arr[ieac]) == in) {
								isFound = true;
								std::cout << "The hash is equal to : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac]) << std::endl;

								out << "Hash : " + in + "\n";
								out << "Original Text : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac]) + "\n";

								if (hash == 0 || hash == 5)
									out << "Hash Type : sha256\n";

								else if (hash == 1)
									out << "Hash Type : md5\n";

								else if (hash == 2)
									out << "Hash Type : sha1\n";

								end = std::chrono::steady_clock::now();
								if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
									out << "Time taken : Less than a minute...\n";
								else
									out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

								out.close();
								break;
							}
						}

						if (isFound == true)
							break;
					}

					if (isFound == true)
						break;
				}

				if (isFound == true)
					break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					for (int iea = 0; iea < 62; iea++) {
						for (int ieac = 0; ieac < 62; ieac++) {
							for (int ieacb = 0; ieacb < 62; ieacb++) {
								if (get_hash_type(hash, arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb]) == in) {
									isFound = true;
									std::cout << "The hash is equal to : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb]) << std::endl;

									out << "Hash : " + in + "\n";
									out << "Original Text : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb]) + "\n";

									if (hash == 0 || hash == 5)
										out << "Hash Type : sha256\n";

									else if (hash == 1)
										out << "Hash Type : md5\n";

									else if (hash == 2)
										out << "Hash Type : sha1\n";

									end = std::chrono::steady_clock::now();
									if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
										out << "Time taken : Less than a minute...\n";
									else
										out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

									out.close();
									break;
								}
							}

							if (isFound == true)
								break;
						}

						if (isFound == true)
							break;
					}

					if (isFound == true)
						break;
				}

				if (isFound == true)
					break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					for (int iea = 0; iea < 62; iea++) {
						for (int ieac = 0; ieac < 62; ieac++) {
							for (int ieacb = 0; ieacb < 62; ieacb++) {
								for (int ieacbe = 0; ieacbe < 62; ieacbe++) {
									if (get_hash_type(hash, arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe]) == in) {
										isFound = true;
										std::cout << "The hash is equal to : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe]) << std::endl;

										out << "Hash : " + in + "\n";
										out << "Original Text : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe]) + "\n";

										if (hash == 0 || hash == 5)
											out << "Hash Type : sha256\n";

										else if (hash == 1)
											out << "Hash Type : md5\n";

										else if (hash == 2)
											out << "Hash Type : sha1\n";

										end = std::chrono::steady_clock::now();
										if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
											out << "Time taken : Less than a minute...\n";
										else
											out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

										out.close();
										break;
									}
								}

								if (isFound == true)
									break;
							}

							if (isFound == true)
								break;
						}

						if (isFound == true)
							break;
					}

					if (isFound == true)
						break;
				}

				if (isFound == true)
					break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					for (int iea = 0; iea < 62; iea++) {
						for (int ieac = 0; ieac < 62; ieac++) {
							for (int ieacb = 0; ieacb < 62; ieacb++) {
								for (int ieacbe = 0; ieacbe < 62; ieacbe++) {
									for (int ieacbea = 0; ieacbea < 62; ieacbea++) {
										if (get_hash_type(hash, arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe] + arr[ieacbea]) == in) {
											isFound = true;
											std::cout << "The hash is equal to : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe] + arr[ieacbea]) << std::endl;

											out << "Hash : " + in + "\n";
											out << "Original Text : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe] + arr[ieacbea]) + "\n";

											if (hash == 0 || hash == 5)
												out << "Hash Type : sha256\n";

											else if (hash == 1)
												out << "Hash Type : md5\n";

											else if (hash == 2)
												out << "Hash Type : sha1\n";

											end = std::chrono::steady_clock::now();
											if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
												out << "Time taken : Less than a minute...\n";
											else
												out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

											out.close();
											break;
										}

										if (isFound == true)
											break;
									}

									if (isFound == true)
										break;
								}

								if (isFound == true)
									break;
							}

							if (isFound == true)
								break;
						}

						if (isFound == true)
							break;
					}

					if (isFound == true)
						break;
				}

				if (isFound == true)
					break;
			}
		}

		if (isFound == false) {
			for (int i = 0; i < 62; i++) {
				//std::cout << sha256(arr[i]) << std::endl;
				for (int ie = 0; ie < 62; ie++) {
					for (int iea = 0; iea < 62; iea++) {
						for (int ieac = 0; ieac < 62; ieac++) {
							for (int ieacb = 0; ieacb < 62; ieacb++) {
								for (int ieacbe = 0; ieacbe < 62; ieacbe++) {
									for (int ieacbea = 0; ieacbea < 62; ieacbea++) {
										for (int ieacbeac = 0; ieacbeac < 62; ieacbeac++) {
											if (get_hash_type(hash, arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe] + arr[ieacbea] + arr[ieacbeac]) == in) {
												isFound = true;
												std::cout << "The hash is equal to : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe] + arr[ieacbea] + arr[ieacbeac]) << std::endl;

												out << "Hash : " + in + "\n";
												out << "Original Text : " + (arr[i] + arr[ie] + arr[iea] + arr[ieac] + arr[ieacb] + arr[ieacbe] + arr[ieacbea] + arr[ieacbeac]) + "\n";

												if (hash == 0 || hash == 5)
													out << "Hash Type : sha256\n";

												else if (hash == 1)
													out << "Hash Type : md5\n";

												else if (hash == 2)
													out << "Hash Type : sha1\n";

												end = std::chrono::steady_clock::now();
												if (std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() < 1)
													out << "Time taken : Less than a minute...\n";
												else
													out << "Time taken : " << std::chrono::duration_cast<std::chrono::minutes>(end - begin).count() << " minutes\n";

												out.close();
												break;
											}

											if (isFound == true)
												break;
										}

										if (isFound == true)
											break;
									}

									if (isFound == true)
										break;
								}

								if (isFound == true)
									break;
							}

							if (isFound == true)
								break;
						}

						if (isFound == true)
							break;
					}

					if (isFound == true)
						break;
				}

				if (isFound == true)
					break;
			}
		}
		for (int i = 0; i <= 3; i++) 
			std::cout << std::endl;	
	}

	return 0;
}