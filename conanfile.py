from conans import ConanFile, CMake

class UtilsConan(ConanFile):
    name = "utils"
    version = "1.0.0"
    license = "MIT"
    author = "Your Name <youremail@example.com>"
    url = "https://yourlibraryrepository.com"
    description = "A collection of utility functions for C programming."
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    
    def source(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.c", dst="src", src="src")
        
    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.a", dst="lib", keep_path=False)
    
    def package_info(self):
        self.info.libs = ["utils"]
