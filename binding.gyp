{
  "targets": [
    {
      "target_name": "clipboard",
      "sources": [ "src/cpp/*.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "configurations": {
        "Release": {
          "msvs_settings": {
            "VCCLCompilerTool": {
              "ExceptionHandling": 1
            }
          }
        }
      }
    }
  ]
}