<p align="center">
  <img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
</p>
<p align="center">
    <h1 align="center">SOUND-SYNTHESIZER</h1>
</p>
<p align="center">
    <em>Unleash Your Musical Creativity with Sound-Synthesizer!</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/Destray32/sound-synthesizer?style=default&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/Destray32/sound-synthesizer?style=default&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/Destray32/sound-synthesizer?style=default&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/Destray32/sound-synthesizer?style=default&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
	<!-- default option, no dependency badges. -->
</p>
<hr>

##  Quick Links

> - [ Overview](#-overview)
> - [ Features](#-features)
> - [ Repository Structure](#-repository-structure)
> - [ Modules](#-modules)
> - [ Getting Started](#-getting-started)
>   - [ Installation](#-installation)
>   - [ Running sound-synthesizer](#-running-sound-synthesizer)
>   - [ Tests](#-tests)
> - [ Project Roadmap](#-project-roadmap)
> - [ Contributing](#-contributing)
> - [ License](#-license)
> - [ Acknowledgments](#-acknowledgments)

---

##  Overview

The sound-synthesizer project is a software application that allows users to create and manipulate sound synthesizers. With a user-friendly interface, it empowers musicians and sound enthusiasts to generate unique sounds and music compositions. The project's value proposition lies in its ability to provide a platform for creative expression and experimentation with sound synthesis. Users can explore different synthesis techniques, adjust parameters, and create custom sounds to enhance their music production process. Overall, the sound-synthesizer project aims to democratize sound synthesis and facilitate the exploration of new sonic possibilities.

---


---

##  Repository Structure

```sh
└── sound-synthesizer/
    ├── bin
    │   └── Win32-Debug
    │       └── sound-synthesizer.pdb
    ├── includes
    │   └── olcNoiseMaker.h
    ├── sound-synthesizer
    │   ├── bell.cpp
    │   ├── bell.h
    │   ├── definicje.h
    │   ├── envelope-adsr.cpp
    │   ├── envelope-adsr.h
    │   ├── Envelope.cpp
    │   ├── Envelope.h
    │   ├── helperfunctions.cpp
    │   ├── helperfunctions.h
    │   ├── instrument.cpp
    │   ├── instrument.h
    │   ├── note.cpp
    │   ├── note.h
    │   ├── sound-synthesizer.cpp
    │   ├── sound-synthesizer.vcxproj
    │   ├── sound-synthesizer.vcxproj.filters
    │   └── sound-synthesizer.vcxproj.user
    └── sound-synthesizer.sln
```

---

##  Modules

<details closed><summary>.</summary>

| File                                                                                                      | Summary                                                                                                                                                                                                                                                                                                                                                                                                                            |
| ---                                                                                                       | ---                                                                                                                                                                                                                                                                                                                                                                                                                                |
                                                                                                                                |
| [sound-synthesizer.sln](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer.sln) | The code snippet is located in the sound-synthesizer directory of the parent repository. It is part of a Visual Studio solution and implements a sound synthesizer. The code includes various classes and files related to sound generation and instrument handling, such as note, instrument, envelope, and helper functions. The purpose of this code is to provide the main functionality of the sound synthesizer application. |

</details>

<details closed><summary>includes</summary>

| File                                                                                                   | Summary                                                                                                                                                                                                                                                                                                                                                                                                                     |
| ---                                                                                                    | ---                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [olcNoiseMaker.h](https://github.com/Destray32/sound-synthesizer/blob/master/includes\olcNoiseMaker.h) | This code snippet represents a class called `olcNoiseMaker` that provides functionality for creating and playing audio waveforms. It allows users to generate waveforms, specify audio output device, sample rate, number of channels, and more. It handles communication with the sound card to play the generated audio. The snippet also includes helper functions for clipping and enumerating available audio devices. |

</details>

<details closed><summary>sound-synthesizer</summary>

| File                                                                                                                                                | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| ---                                                                                                                                                 | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [bell.h](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\bell.h)                                                       | The code in `bell.h` is a part of the `sound-synthesizer` repository. It defines a Bell instrument that generates sound based on time and note input. This code contributes to the architecture of the sound synthesizer by implementing a specific instrument type.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [definicje.h](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\definicje.h)                                             | The code snippet in the file `definicje.h` defines constants for different types of waveforms and a data type for frequency. It has a crucial role in the parent repository's architecture by providing easy access to waveform types and ensuring consistency in frequency calculations.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [envelope-adsr.cpp](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\envelope-adsr.cpp)                                 | The code snippet in envelope-adsr.cpp is responsible for implementing the ADSR envelope functionality in the sound synthesizer. It calculates the amplitude of a note based on its attack, decay, sustain, and release times. This code is an essential component of the overall architecture of the sound synthesizer repository.                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [envelope-adsr.h](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\envelope-adsr.h)                                     | This code snippet is a header file for an ADSR envelope implementation in the sound-synthesizer repository. It defines a struct that represents an ADSR envelope, with properties such as attack time, decay time, release time, and sustain amplitude. The struct also includes a function to calculate the amplitude of the envelope at a given time. This code contributes to the sound synthesis functionality of the parent repository by providing a way to control the envelope shape of synthesized sounds.                                                                                                                                                                                                                                                           |
| [Envelope.cpp](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\Envelope.cpp)                                           | The code in `Envelope.cpp` is an implementation file that includes the header file `envelope-adsr.h`. It is part of the sound synthesizer repository and contributes to the architecture by providing functionality related to the ADSR envelope of the synthesizer's sound generation.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [Envelope.h](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\Envelope.h)                                               | The Envelope.h code snippet defines an abstract envelope structure that calculates the amplitude of a sound at a given time. This is a critical component in the sound-synthesizer repository's architecture for generating and manipulating sound.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [helperfunctions.cpp](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\helperfunctions.cpp)                             | This code snippet in `helperfunctions.cpp` provides a function for scanning a button press and returning the corresponding virtual key code. It is part of the `sound-synthesizer` repository.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [helperfunctions.h](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\helperfunctions.h)                                 | This code snippet in `helperfunctions.h` defines a function `SkanowaniePrzycisku` that scans a button code and returns it as an integer. It is part of the `sound-synthesizer` repository and contributes to the helper functions in the architecture.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [instrument.cpp](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\instrument.cpp)                                       | The code snippet in `instrument.cpp` implements the `SetVolume` function for the `Instrument` class. This function sets the volume of the instrument.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [instrument.h](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\instrument.h)                                           | Code Summary:The code in the instrument.h file defines a struct called Instrument. It includes a volume control, an envelope for shaping the sound, and a sound function that takes in the time, a note, and a flag indicating if the note is finished. The sound function is a virtual function that needs to be implemented by derived classes.Code Role:The Instrument struct is a key component of the sound-synthesizer repository. It serves as a base class for various instruments in the synthesizer. It provides a common interface and functionality for defining and playing different instrument sounds. The code in this file contributes to the overall architecture of the repository by establishing a foundational structure for instrument implementation. |
| [note.cpp](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\note.cpp)                                                   | The `note.cpp` file is part of the `sound-synthesizer` repository and contains the implementation of the `Note` class. The class represents a musical note with properties such as id, on/off timestamps, activity status, and channel assignment. It is a critical component of the sound synthesizer's architecture.                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [sound-synthesizer.cpp](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\sound-synthesizer.cpp)                         | This code snippet is part of a sound synthesizer repository. It includes functions for generating and managing audio signals, handling keyboard inputs, and controlling note playback. The main role of this code is to generate audio based on the notes played on the keyboard.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [sound-synthesizer.vcxproj](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\sound-synthesizer.vcxproj)                 | This code snippet is part of the sound-synthesizer repository. It contains the configuration file for the sound-synthesizer project, specifying the build targets, platform settings, and dependencies. The code manages the build configurations for different platforms, such as Debug/Release and Win32/x64.                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [sound-synthesizer.vcxproj.filters](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\sound-synthesizer.vcxproj.filters) | This code snippet, found in the `sound-synthesizer` repository, is responsible for managing the filters and file inclusions in the Visual Studio project. It organizes the source, header, and resource files into appropriate categories for better project management.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [sound-synthesizer.vcxproj.user](https://github.com/Destray32/sound-synthesizer/blob/master/sound-synthesizer\sound-synthesizer.vcxproj.user)       | The code snippet in the file sound-synthesizer.vcxproj.user configures the project settings to hide all files in the repository structure. It plays a critical role in maintaining the repository's architecture by managing the visibility of files.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |

</details>

---

##  Getting Started

***Requirements***

Ensure you have the following dependencies installed on your system:

* **C**

###  Installation

1. Clone the sound-synthesizer repository:

```sh
git clone https://github.com/Destray32/sound-synthesizer
```

2. Change to the project directory:

```sh
cd sound-synthesizer
```

3. Install the dependencies:

```sh
gcc -o myapp main.c
```

###  Running sound-synthesizer

Use the following command to run sound-synthesizer:

```sh
./myapp
```

###  Tests

To execute tests, run:

```sh
/* No common unit test framework in C */
```

---


##  Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Submit Pull Requests](https://github/Destray32/sound-synthesizer/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github/Destray32/sound-synthesizer/discussions)**: Share your insights, provide feedback, or ask questions.
- **[Report Issues](https://github/Destray32/sound-synthesizer/issues)**: Submit bugs found or log feature requests for Sound-synthesizer.

<details closed>
    <summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your GitHub account.
2. **Clone Locally**: Clone the forked repository to your local machine using a Git client.
   ```sh
   git clone https://github.com/Destray32/sound-synthesizer
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to GitHub**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.

Once your PR is reviewed and approved, it will be merged into the main branch.

</details>

---

[**Return**](#-quick-links)

