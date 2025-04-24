# HowToUseUnrealEngine 프로젝트

언리얼 엔진 학습을 위한 통합 문서화 프로젝트입니다. 이 프로젝트는 언리얼 엔진 5.5 버전을 기반으로 개발되었습니다.

## 프로젝트 개요

이 프로젝트는 언리얼 엔진의 다양한 기능과 사용법을 체계적으로 학습할 수 있도록 구성되었습니다. 초보자부터 중급자까지 단계별로 학습할 수 있는 레벨 기반 구조를 채택했습니다.

## 시작하기

1. 프로젝트 클론하기

```
git clone https://github.com/dogeinhyeok/HowToUseUnrealEngine.git
```

2. Visual Studio 프로젝트 생성하기

   - 프로젝트 폴더에서 HowToUseUnrealEngine.uproject 파일을 마우스 오른쪽 버튼으로 클릭합니다
   - "Generate Visual Studio project files" 메뉴를 선택합니다
   - 새로 생성된 HowToUseUnrealEngine.sln 솔루션 파일을 엽니다

3. Visual Studio 2022에서 프로젝트 설정

   - 솔루션 구성을 'Development Editor'로 설정합니다
   - 솔루션 플랫폼을 'Win64'로 설정합니다
   - 솔루션 탐색기에서 HowToUseUnrealEngine 프로젝트를 마우스 오른쪽 버튼으로 클릭하고 '디버그 > 새 인스턴스 시작'을 선택합니다

4. Source 폴더 탐색하며 학습하기

   - Source/HowToUseUnrealEngine 폴더에서 C++ 코드 구조를 확인합니다
   - 프로젝트 구성 방식과 모듈 구조를 이해합니다
   - 각 Target.cs 파일을 통해 빌드 설정을 학습합니다

## 개발 환경

- 언리얼 엔진 5.5
- Visual Studio 2022
- Windows 10/11

## 프로젝트 구조

- **Source/**: C++ 소스 코드
- **Content/**: 블루프린트, 에셋, 레벨 등 콘텐츠
- **Config/**: 프로젝트 설정 파일

## 문서화 규칙

자세한 코드 주석 및 문서화 규칙은 .cursor/rules/ 폴더를 참조해주세요.

## 기여하기

1. 프로젝트를 포크합니다.
2. 새로운 브랜치를 생성합니다.
3. 변경사항을 커밋합니다.
4. 브랜치에 푸시합니다.
5. Pull Request를 제출합니다.
