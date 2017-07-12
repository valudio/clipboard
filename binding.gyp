{
  "targets": [
    {
      "target_name": "selectedText",
      "sources": [ "cpp/*.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}