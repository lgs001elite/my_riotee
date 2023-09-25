# Riotee SDK template project

This is a template project for developing a Riotee application.
The Makefile-based project optionally supports Visual Studio Code.

## Usage

Follow the instructions to install the [Riotee SDK](https://github.com/NessieCircuits/Riotee_Runtime) and its dependencies to a location on your computer.

If you want to develop your application in a GitHub repository, make sure you're signed in to GitHub and click on the green `Use this template` button on this repository's GitHub page to create your own repository from this template.
Give your repository a name, for example, `my-riotee-app`.
Clone your new repository using its URL.

```shell
git clone git@github.com:yourusername/my-riotee-app.git
```

If you're not using GitHub, you can download this template by clicking on `Code->Download Zip` on the repository's GitHub page and extracting the downloaded file to a location on your computer.

### Command-line

If you're planning to use Visual Studio Code for development you can skip this step and continue reading [here](#visual-studio-code).

If you want to build the project from the commandline or some other IDE, set an environment variable called `RIOTEE_SDK_ROOT` to the corresponding path on your machine.

```shell
export RIOTEE_SDK_ROOT=[PATH TO RIOTEE SDK]
```
If the arm-none-eabi-gcc toolchain is not on your path, point to it with another environment variable:

```shell
export GNU_INSTALL_ROOT=[PATH TO TOOLCHAIN]
```
As an alternative to these environment variables, you can also set the two variables at the top of the project's [Makefile](./Makefile).

Now build the project and upload it to your Riotee device with
```
make flash
```
### Visual Studio Code

 - Install Visual Studio Code from the [official website](https://code.visualstudio.com/) and open it.
 - On the left panel select `Extensions`, search for the `C/C++ Extension Pack` and install it.
 - Open the project's folder via `File->Open Folder`.

Adjust the three configuration keys in [.vscode/settings.json](.vscode/settings.json) according to your setup:
 - `rioteeSdkRoot`: Path to the Riotee SDK
 - `operSys`: Mac, Linux or Win32
 - `gnuInstallRoot`: Location of arm-none-eabi toolchain, leave empty if it is in your `PATH` variable already.

Restart Visual Studio Code.
Open `main.c` and check that code-completion works and that all imports are correctly resolved. For example, selecting `riotee_wait_cap_charged()` and pressing `F12` should take you straight into the SDK's code.

If you installed the `riotee-probe` Python package into a virtual environment when setting up the SDK, press `Ctrl`+`Shift`+`p`, search for `Python: Select Interpreter`, and point it to the Python executable of your virtual environment.

To install keyboard shortcuts, press `Ctrl`+`Shift`+`p`, type `Open Keyboard Shortcuts (JSON)` and press `Enter`, insert the following keybindings and save the file:

```
    {
        "key": "ctrl+alt+b",
        "command": "workbench.action.tasks.runTask",
        "args": "build"
    },
    {
        "key": "ctrl+alt+c",
        "command": "workbench.action.tasks.runTask",
        "args": "clean"
    },
    {
        "key": "ctrl+alt+u",
        "command": "workbench.action.tasks.runTask",
        "args": "flash"
    },
```

Now you can conveniently build, clean and flash the code using the corresponding keyboard shortcuts.