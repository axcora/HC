---
layout: themes-detil.cax
title: Minimal Dotnet Themes DAX SSG
description: Free download and open source code dotnet SSG DAX C# Minimalis clean project website themes template.
image: dotnet/dotnetssg_rymnid.jpg
features:
 - Dotnet
 - Microsoft Tech
 - C#
 - DAX Template
 - Auto SEO
 - Auto Collections
 - YAML / JSON Data
 - Markdown Content
 - Axcora Zetaa Core Engine
 - Modern Host support netlify vercel cloudflare Github Pages and others 
 - Build production host firebase surge cpanel vps direct admin plesk and others
download: https://creativitaz.gumroad.com/l/dax
demo: https://dax.axcora.com/minimal/
tags:
  - themestemplate
  - website themes
  - website template
  - dotnet
  - themes
  - landing page
  - template
  - featuredthemes
  - dotnetthemes
  - jamstackthemes
  - freethemes
date: 2026-08-10
---

### Introduction

DAX - Pure [C#](https://dotnet.microsoft.com/en-us/languages/csharp) Slim Static Site Generator [.NET](https://dotnet.microsoft.com/)

Built for performance. DAX generates pure static HTML with zero JavaScript bloat. Perfect Lighthouse scores out of the box, without complex tooling or frameworks.

Without complex configuration—much like Jamstack-based SSGs such as Eleventy (11ty), Jekyll, or [Astro.js](https://astro.build)—Dax precisely meets your needs in the modern SSG era.

### Features

DAX Features:
+ Auto SEO 
+ Auto Metatag
+ Auto Twitter Card
+ Auto Open Graph
+ Auto JSON LD
+ Auto Collections
+ Auto Pagination
+ Auto Next Prev Post
+ Fast Build
+ JAMSTACK Taste
+ YAML Data Support
+ Json Data Support
+ Write on Markdown md files
+ Easy Installation
+ Built with pure C#
+ Slim Blast Fast .NET SSG

### Installation

for first make sure you have download dotnet : https://dotnet.microsoft.com/en-us/download

next you can open terminal cmd and run this command :

SLIM VERSION
```
git clone https://github.com/mesinkasir/dax.git
cd dax
dotnet run -- build
dotnet run -- start
open localhost:8080
```

DAX VERSION
```
git clone https://github.com/mesinkasir/dax.git
cd dax
dotnet publish -c Release -o .
dax build
dax start
open localhost:8080
```

### Architecture

The DAX Architecture
```
dax/
├── Program.cs              # Single-file SSG engine
├── Dax.csproj              # net9.0, PublishSingleFile
├── README.md
├── LICENSE (MIT)
├── .gitignore
├── .github/
│   └── workflows/
│       └── build.yml       # CI: build + test
│       └── deploy.yml      # Github Pages Deploy
├── _data/                  # Global data (auto-loaded)
│   ├── metadata.json       # site.title, site.url
│   ├── config.yaml         # Free YAML - nested list support
│   └── nav.json
├── content/                # File-based content (auto collections)
│   ├── index.md            # /  (free frontmatter: hero, image, etc)
│   ├── tags.md             # /tags/ (auto tags list)
│   ├── posts.md            # /posts/ controller -> collection: posts, pagination: 6
│   └── posts/
│       ├── hello.md        # /posts/hello/ - tags: [csharp, dax]
│       └── second.md
├── templates/
│   ├── layouts/
│   │   ├── base.dax        # Base layout
│   │   ├── home.dax        # Home + hero.list, config.list
│   │   ├── posts-list.dax  # Uses pagination.items
│   │   ├── post.dax        # Single post + prev_post/next_post
│   │   ├── tag.dax         # Single tag page
│   │   └── tags-list.dax   # All tags index
│   └── partials/
│       ├── header.dax      
│       ├── footer.dax
│       └── seo.dax
├── public/
│   └── css/style.css
└── site/                   # Generated (gitignored)
    ├── index.html
    ├── posts/
    ├── tags/
    ├── sitemap.xml
    ├── robots.txt
    └── rss.xml
```

### Configuration

For first you need to setup your site , open on `_data/metadata.yaml`.

Update with your site configuration
```
title: MINIMAL
description: "Minimal is a simple and clean theme for DAX Static Site Generator. It is designed to be lightweight and fast, with a focus on content and readability."
url: /minimal/
navbar: 
  title: MINIMAL
  list: 
    - title: "Home"
      url: "/minimal/"
    - title: "About"
      url: "/about/"
    - title: "Blog"
      url: "/posts/"
    - title: "Docs"
      url: "/docs/"
    - title: "Deploy"
      url: "/deploy/"
    - title: "Download"
      url: "https://creativitaz.gumroad.com/l/dax"
    - title: "Github"
      url: "https://github.com/mesinkasir/dax/"
about: 
  title: "DAX .NET Static Site Generator"
  description: "DAX is a slim .NET SSG. Build static sites 50x faster than Blazor SSG. No WASM bloat, just pure static HTML. For .NET devs who hate Blazor slow."
  image: /img/dax-primary-logo.webp
```

Information :
+ Default SEO title,description,url.
+ Navbar to setup your navbar
+ About this is to udpate your post article widget.

### Media

DAX is support with your static media such css, js , image, file, video and others. just upload your media file on `public` folder.

### Home Page

To update home page open on `content/index.md`.

frontmatter: 
```
---
title: Home
layout: home.dax
hero:
  title: Hello DAX
  description: Slim SSG
  list:
    - name: Blog
      url: /posts/
      meta:
        icon: star
---
Welcome!
```

### Static Page

To update static page you can access on `content` then create your new markdown file, example `about.md`.

format: 
```
---
layout: minimal/page.dax
title: Why DAX (C#) is Faster & Easier than CAX (C)
description: CAX was built in C - blazing fast but painful to hack. DAX rewrites the same philosophy in Pure C# and wins on DX.
---
Article here...
```

### Blog List

To update blog list you can access on `content/posts.md`.

format: 
```
---
collection: posts
title: Blog list
description: List of articles
pagination: 6
layout: posts-list.dax
---
```

### Template Layout

You can update your templating on `templates`.
+ Layouts is for you layout such base.dax and others
+ Partilas is your modular widget or section such: navbar.dax


### Support

+ [Support via PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JVZVXBC4N9DAN)
+ [Support via Github](https://github.com/sponsors/mesinkasir)
+ [Support via Gumroad](https://creativitaz.gumroad.com/coffee)
