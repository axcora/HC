---
layout: themes-detil.cax
title: New Static SIte Generator AX
description: AX New Modern Static Site Generator - AX SSG by Axcora is the perfect solution for anyone looking to build a static site generator that is both fast and ultra-lightweight. Designed for simplicity, AX SSG does not require any node_modules, making setup instant and performance blazing fast.
image: axcora/ax-static-site-generator-starter_hhiare.webp
features:
 - JSON
 - YAML
 - SSG
 - Fast Website
 - Simple
 - No Node_Modules
 - Markdown
 - SEO Ready
 - All Static Hosting support Vercel, Cloudflare, Netlify and others.
 - All PHP Hosting support Cpanel, Plesk, Direct Admin , VPS and others.
download: https://creativitaz.gumroad.com/l/ax-starter
demo: https://ax.axcora.com/
tags:
  - themestemplate
  - website themes
  - website template
  - themes
  - template
  - freethemes
  - featuredthemes
  - otherthemes
  - others
date: 2025-09-04
---
### Introduction

**Axcora AX SSG: A Lightweight Static Site Generator with No `node_modules`**

Axcora **AX SSG** stands out among static site generators for its **minimalist architecture**, 
delivering **exceptional speed** while completely eliminating the heavy `node_modules` directory that characterizes most modern SSGs[1]. This approach makes AX SSG remarkably **lightweight and easy to manage**—ideal for developers seeking maximum efficiency with minimal complexity.

Unlike traditional static site generators such as Jekyll, Hugo, or Gatsby, which often require managing thousands of dependencies via `node_modules` and come with steep setup requirements, AX SSG keeps things simple. It uses only **essential JavaScript libraries** 
and boasts a transparent file structure based on Markdown content, Handlebars templates, and configuration in basic JSON or YAML. This minimalism ensures **installation is fast**, the learning curve is gentle, and local storage requirements remain tiny.

**Key Advantages of AX SSG:**

- **No node_modules:** AX SSG projects **do not generate a node_modules folder**, reducing clutter, minimizing storage, and avoiding dependency hell.
- **Super-fast builds:** Without bulky dependencies, **site build times are measured in seconds**. This speed makes iterative development and deployment frictionless.
- **Easy asset management:** Developers select just the CSS or JS components needed for a given page or template. Axcora automatically ships only the required, minified assets for every build, so **no unused code is ever bundled**, resulting in faster loading sites.
- **Integrated features:** AX SSG includes built-in pagination, tag pages, metadata (RSS, sitemap, robots.txt), and a recursive templating engine for advanced layout flexibility, all without third-party plugins or additional setup.
- **Deploy anywhere:** Due to its compact output and lack of complex dependencies, AX SSG sites are easy to deploy on any static hosting service.
- **Ideal use cases:** Blogs, documentation, landing pages, and portfolios that need simple configuration, easy updates, and top-tier performance.

In comparison, **conventional SSGs** provide rich plugin ecosystems and broad functionality at the cost of greater complexity, persistent maintenance, and larger project footprints. AX SSG reimagines the developer experience, showing how **minimalism enables both power and speed**—making it a compelling choice for modern static web development.

---

### Installation

Need to download node js - [Download Node Js](https://nodejs.org/en/download/)

#### Install via Source Code

+ [Download Source Code file](https://creativitaz.gumroad.com/l/ax-starter)
+ Create new project and upload into your project folder
+ Extract source code into your project folder
+ Access via terminal eg `cd C:\Users\Mypc\project`
+ And run `npm run dev`
+ Open `localhost:3000`

#### Install AX Starter

You can clone from our github repo
```
git clone https://github.com/mesinkasir/ax-starter.git
cd ax-starter
npm run dev
# open localhost:3000
```

#### Install AX Global

Install AX SSG Global in your device
```
npm i -g axcora-ax
```
Create new project
```
ax init myproject
```
Access your project
```
cd myproject
```
Run your project
```
ax dev
```
Open web browser
```
localhost:3000
```
Build for production
```
ax build
```
Upload on your hosting
```
dist
```

---

### Configuration

For first you need to setup your site , acces in to `data/site.json`

And update it.

```
{
  "name": "AX SSG",
  "lang": "en",
  "locale": "en-US",
  "description": "Demo site built with AX SSG - minimalist static site generator with modern design - by Axcora tech",
  "url": "http://localhost:3000",
  "icon": "/assets/img/logo.png",
  "author": {
              "name": "Axcora Team", 
              "url": "https://ax.axcora.com" 
   },
  "blog_list_title": "The Blog",
  "show_blog_list": "6",
  "title": "AX",
  "nav": [
    { "title": "Home", "url": "/" },
    { "title": "Blog", "url": "/blog/" },
    { "title": "Tags", "url": "/tags.html" },
    { "title": "About", "url": "/about.html" }
  ],
  "social": [
    { "name": "GitHub", "url": "https://github.com/sponsors/mesinkasir/"},
    { "name": "Website", "url": "https://ax.axcora.com/" }
  ]
}
```

---

### Home Page

to update home page you can access on `content/pages/index.md`

```
---
title: Welcome to Ax SSG
description: "A lightning-fast, dependency-minimal static site generator"
---
![AX SSG](/assets/img/ax-1.jpg)

Website speed isn't just a technical metric—it's a measure of user experience and business impact. Study after study shows that users are less likely to engage, convert, or return to slow websites. Google and other search engines now factor speed heavily into rankings, making fast-loading sites a top priority for SEO.
```

---

### Static Page

to create new or update static page you can access on `content/pages/` and create a static page, eg , `about.md`

```
---
title: "About AX SSG"
description: A Minimalist Static Site Generator Focused on Simplicity and Speed
---
Axcora AX SSG by axcora team

![AX SSG](/assets/img/axcora.jpg)

Axcora AX SS
```

---

### Blog Post

If you want to update and create new blog post article you can access on `content/blog` and create your new markdown file.

```
---
title: "Minimalism Over Bloat"
description: "Ditching Node_Modules - Minimalism Over Bloat"
image: "/assets/img/axcora.jpg"
date: "2025-09-03"
tags: [minimalism, dev practices]
---

No more dependency jungle. With AX, only core JavaScript and a few proven libraries are needed.
```

---

### AUTO SEO Injection

AX is uses auto SEO injection, such meta title, open graph, twitter card, sitemap.xml , RSS.xml all in one SEO for your project.

---

### Static Files

If you want to upload your static file in root you can drop your static file into `static` folder.

---

### Assets Files

If you want to upload your assets file such css, js, image and others ,you can drop your file into `assets` folder.

---

### AX Complete Docs

You can also learn about ax templating on ax documentation page.

[AX Documentation](https://ax.axcora.com/docs/)

---