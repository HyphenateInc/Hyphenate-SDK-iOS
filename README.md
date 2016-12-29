# Hyphenate-SDK-iOS
- doc folder: SDK documentation.
- HyphenateFull-SDK folder: Common features + video/audio calling.
- HyphenateSDK folder: Common features.

iOS Demo: [https://github.com/HyphenateInc/Hyphenate-Demo-iOS](https://github.com/HyphenateInc/Hyphenate-Demo-iOS "IMDemo")

iOS Demo is dependending on EaseUI library:[https://github.com/HyphenateInc/Hyphenate-EaseUI-iOS](https://github.com/HyphenateInc/Hyphenate-EaseUI-iOS "EaseUI")

## Installation with CocoaPods

CocoaPods is a dependency library manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like Hyphenate in your projects. For further detail, please visit https://cocoapods.org

```bash
$ gem install cocoapods
```

Add the following line to Podfile
```ruby
source 'https://github.com/CocoaPods/Specs.git'

target 'projectTarget' do
  pod 'Hyphenate'
end
```

run the following command:
```bash
$ pod install
```
