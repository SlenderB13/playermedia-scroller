#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <strstream>
#include <thread>

std::string text_scroller(std::string text, int width, int delay) {
	std::string output_text = text;

	std::string result = output_text.substr(1);

	return result + std::string(1, ' ');
}

int main() {
	std::string text = "i am a scrolling text!!!!!";
	std::string output = text;

	int width = 20;
	int delay = 200;
	int metadata_size_idx = 0;


	std::string PLAYING_STATUS = "Playing";

	while (true) {
		// gets playerctl status command result
		FILE* status_command = popen("playerctl status", "r");
		char status_buffer[128];
		std::string status;

		while(fgets(status_buffer, sizeof(status_buffer), status_command) != nullptr) {
			status += status_buffer;
		}
		pclose(status_command);
		
		// gets playerctl metadata command result
		FILE* metadata_command = popen("playerctl metadata --format '{{artist}} - {{title}}'", "r");
		char metadata_buffer[128];
		std::string metadata;

		while(fgets(metadata_buffer, sizeof(metadata_buffer), metadata_command) != nullptr) {
			metadata += metadata_buffer;
		}
		pclose(metadata_command);

		// fgets adds the \n char to the end of the buffer, so we need to remove it
		// if you don't, the == operator may not identify equal values to the strings
		metadata = metadata.substr(0, metadata.size() - 1);
		status = status.substr(0, status.size() - 1);

		if (status == PLAYING_STATUS) {
			output = text_scroller(output, width, delay);

			if (metadata_size_idx == output.size()) {
				output = metadata;
				metadata_size_idx = 0;
			}
			metadata_size_idx ++;
		} else {
			output = metadata;
			metadata_size_idx = 0;
		}

		std::ostrstream stream;

		stream << "%{A1:playerctl play-pause:}" << output << "%{A}";

		std::cout << stream.str() << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}

	return 0;
}
