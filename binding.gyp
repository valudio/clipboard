{
  "targets": [
    {
      "target_name": "selectedText",
      "sources": [ "src/*.cpp" ],
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