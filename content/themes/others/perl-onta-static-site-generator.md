---
layout: themes-detil.cax
title: New Onta PERL SSG
description: PERL Static Site Generator - ONTA is an optimized network template architecture designed for speed and security.
image: others/perl-onta-static-site-generator_clnuqk.jpg
features:
 - Axcora
 - Axcora Zetta Core
 - Starter Project
 - Fast Website
 - Auto SEO
 - Fast Build
 - JSON Data
 - Markdown TXT Format
 - Perl SSG
 - All PHP Hosting support Cpanel, Plesk, Direct Admin , VPS and others via terminal.
download: https://creativitaz.gumroad.com/l/onta
demo: https://onta.axcora.com/
tags:
  - themestemplate
  - website themes
  - website template
  - blog template
  - themes
  - template
  - perlthemes
  - freethemes
  - otherthemes
  - others
date: 2026-08-07
---
### Introduction

ONTA PERL SSG is a professional-grade static site generator engineered for high-performance web architecture. Built on the Axcora Zetta Core philosophy, it provides a seamless bridge between raw content and lightning-fast deployment.

A unique static site generator for [PERL](https://www.perl.org/) developer,built with perl make easy for you to run ONTA SSG in your cloud host via terminal.

### Installation

How to install Onta Perl SSG

#### installation Local Devices

If you want to run on your local device make sure you have install
+ [Download PERL](https://www.perl.org/get.html)
+ [Strawberry PERL](https://strawberryperl.com/)

Next open terminal and check perl version
```
perl -v
```

Next you need to download ONTA PERL SSG

Download ZIP File via Gumroad: https://creativitaz.gumroad.com/l/onta

Github Repo: https://github.com/mesinkasir/onta-perl-ssg

Or simply step you can clone the repo via terminal , create your project folder and open terminal CMD

run this command
```
git clone https://github.com/mesinkasir/onta-perl-ssg
cd onta-perl-ssg
perl onta.pl
```
The engine will scan your content/ directory, process the layout/, and generate a fully optimized static site in the parent or target public directory.

#### installation Cloud Host

First make sure your hosting is support perl and terminal, next access your host terminal and check perl version with run this command 

```
perl -v
```

Next you need to download ONTA PERL SSG

Download ZIP File via Gumroad: https://creativitaz.gumroad.com/l/onta

Github Repo: https://github.com/mesinkasir/onta-perl-ssg

Or simply step you can clone the repo via terminal , create your project folder on dir /root / or subdir and open terminal CMD

run this command
```
git clone https://github.com/mesinkasir/onta-perl-ssg
cd onta-perl-ssg
perl onta.pl
```

### Web Configuration

Website Configuration For first you need to setup your site project, such navbar, footer and others. Open on `onta/config.json` files.

Update this configuratio with your site needs.

```
{
  "site_info": {
    "title": "Onta PERL SSG - High Performance Static Site Generator",
    "description": "Experience the ultimate speed and efficiency with Onta PERL SSG. A professional-grade static site generator built for performance, zero dependencies, and seamless cPanel deployment.",
    "image": "/assets/img/PERL-AXCORA-SSG.webp",
    "favicon": "/assets/img/axcoralogowhite.webp",
    "url": "https://onta.axcora.com"
  },
  "metasocial": {
    "facebook": "https://onta.axcora.com",
    "twitter": "https://onta.axcora.com",
    "twitteruser": "https://onta.axcora.com"
  },
  "navbar": {
    "title": "ONTA SSG",
    "list": [
      { "nav": "Home", "url": "index.html" },
      { "nav": "About", "url": "about.html" },
      { "nav": "Docs", "url": "docs" },
      { "nav": "CSS", "url": "style.html" },
      { "nav": "Blog", "url": "blog" }
    ],
    "button": {
      "text": "Support Us",
      "url": "https://paypal.me/creativitas/"
    }
  },
  "collections": {
    "blog": { "per_page": 6, "url": "/blog" },
    "services": { "per_page": 6, "url": "/services" }
    },
  "footer": {
    "logo": "/assets/img/axcoralogored.webp",
    "title": "Axcora Zetta Core Technology",
    "text": "Empowering web efficiency through Perl-driven automation and lightning-fast static architectures.",
    "menu1": {
      "title": "Explore",
      "list": [
        { "nav": "Home", "url": "index.html" },
        { "nav": "About", "url": "about.html" },
        { "nav": "Docs", "url": "docs" },
        { "nav": "CSS", "url": "style.html" },
        { "nav": "Blog", "url": "blog" }
      ]
    },
    "menu2": {
      "title": "Support",
      "list": [
        { "nav": "Github", "url": "https://github.com/sponsors/mesinkasir" },
        { "nav": "Paypal", "url": "https://paypal.me/creativitas/" },
        { "nav": "Coffee", "url": "https://creativitaz.gumroad.com/coffee" },
        { "nav": "Contact", "url": "contact.html" }
      ]
    },
    "copyrights": "Copyright by Axcora - Built with ONTA PERL SSG"
  }
}
```
+ Site Info : This area to set your site information, for SEO metatag, open graph and twitter card
+ metasocial is for metadata open graph and twitter card Just change all site info and meta social with your site configuration.
+ Navbar : Navbar title is for title, next you can update navbar list on list area, to add new you can simply copy and paste json format. Button is for navbar button area.
+ Collections: Next you can update the collections data article such a blog and services.
+ Footer Area: To update your footer area section.

### Home Index Page

To update your home page you can update  `index.txt` file on `content`

example: `index.txt`

format: 
```
---
title: ONTA PERL SSG | Modern and Fast Static Site Generator
description: Build lightning-fast websites with the power of Perl. No database, no lag, just pure performance.
layout: home
hero_badge: New Evolution
hero_title: Unleash the Power of Perl
hero_subtitle: ONTA is an Optimized Network Template Architecture designed for speed and security.
---
ONTA was engineered from a fundamental need to redefine the balance between architectural simplicity and enterprise-grade performance. 
```

title and description is for your SEO on index page.
Hero to update your hero section on home page.

### Collections Page


To update your collections post such blog or services you can  update .txt file on `content`

Collections list: 

+ blog.txt
+ categories.txt
+ services.txt
+ tags.txt

example: `about.txt`

format: 
```
---
title: Journal & News
description: The latest articles on web development, technology, and automation.
layout: collections-list
---
```

title and description is for your SEO on index page.

### Static Page


To update your static page you can create new or update and delete .txt file on `content`

example: `about.txt`

format: 
```
---
title: Behind the Architecture
description: Learn about the Axcora Zetta Core concept and the engineering of ONTA SSG.
layout: page
---
### Efficiency and Speed
ONTA is built on the **Axcora Zetta Core** brand—a design philosophy that acts as a web and application architect focusing on efficiency. We support technologies ranging from JAMSTACK to deep AI integration.

```

title and description is for your SEO on index page.

### Blog and COllections Posts

Bext you can create update edit and delete CRUD your content in `content/blog` for blog collections, or `content/services` for services collections.

to create new just create new .txt file

implementation: 
```
---
title: Journal & News
description: The latest articles on web development, technology, and automation.
layout: collections-list
---
```

### Support Onta Perl

+ [Support via PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JVZVXBC4N9DAN)
+ [Support via Github](https://github.com/sponsors/mesinkasir)
+ [Support via Gumroad](https://creativitaz.gumroad.com/coffee)
