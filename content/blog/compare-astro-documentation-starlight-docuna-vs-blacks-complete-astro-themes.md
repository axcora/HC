---
layout: blog-detil.cax
title: Head-to-Head: Docuna - Astro Starlight Docs Template - Documentation and Landing vs Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing for Modern Websites
description: Technical breakdown comparing Docuna Astro Starlight Docs Template ($35) and Blacks Astro Multipurpose Template ($65) for modern static websites.
image: astro/starlighttemplate_uyq8cf.jpg
date: 2026-10-31
tags:
  - astro
  - starlight
  - documentation-template
  - portfolio-template
  - dark-template
  - blog-template
  - astro-template
  - premiumthemes
---

## Introduction

Selecting the right starter theme for a modern web project directly influences development speed, maintenance overhead, build performance, and end-user engagement. As static site architectures continue to dominate front-end engineering, frameworks like Astro have gained significant adoption due to their zero-JavaScript-by-default output and flexible content pipelines. However, technical requirements vary wildly depending on the primary purpose of a website. Building a technical documentation hub requires completely different architectural considerations than launching a dark-mode creative portfolio or multimedia showcase.

Developers and project owners frequently face the decision between specialized, task-focused templates and broader, multipurpose solutions. A specialized documentation theme prioritizes content hierarchy, fast client-side searching, code snippet rendering, and structured navigation. On the other hand, a multipurpose theme focuses on visual media presentation, flexible page layouts, portfolio galleries, landing page sections, and integrated blogging engines.

This detailed comparison evaluates two premium Astro templates available in the ecosystem: [Docuna - Astro Starlight Docs Template - Documentation and Landing](/themes/astro/astro-documentation-starlight-docuna/) and [Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing](/themes/astro/blacks-complete-astro-themes/). Both themes operate on top of Astro, offer 100% source code ownership through a single one-time purchase model, and deliver fast static site generation. However, their internal mechanics, layout patterns, target audiences, and functional features cater to distinct operational needs. This review breaks down their code structure, feature sets, customization workflows, and pricing to help you select the optimal template for your next project.

## Overview of Docuna - Astro Starlight Docs Template - Documentation and Landing

Docuna is a dedicated technical documentation and product landing page template engineered around Astro and the official Starlight documentation framework. Designed specifically for software products, developer tools, open-source projects, and technical knowledge bases, Docuna provides a structured environment for authoring high-density written content without requiring developers to build documentation scaffolding from scratch.

At its core, Docuna leverages Starlight to handle file-based content routing, MDX parsing, dark and light theme switching, keyboard-driven client-side search, and hierarchical sidebar navigation. The theme extends default Starlight functionality by supplying a custom homepage landing layout, allowing teams to present high-level product value propositions, feature highlights, and call-to-action buttons right alongside their core documentation.

```text
Docuna Architecture
├── Landing Page (Product introduction, hero, features)
└── Starlight Engine (Docs, sidebar navigation, keyboard search, MDX parsing)
```

Offered at a price point of $35, [Docuna - Astro Starlight Docs Template - Documentation and Landing](/themes/astro/astro-documentation-starlight-docuna/) delivers full source code control without recurring licensing fees. Its build output consists of static HTML and minimal CSS, making it capable of achieving exceptional performance scores on modern web analytics tools. Installation relies on standard Node.js package management workflows, enabling developers to clone, install dependencies, configure sidebar trees via configuration files, and deploy static assets directly to hosts like Cloudflare Pages or GitHub Pages.

## Overview of Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing

Blacks is a full-featured, dark-themed multipurpose template crafted for creators, photographers, agencies, and multidisciplinary professionals who require a comprehensive digital presence. Unlike single-purpose templates, Blacks combines multiple website formats into a unified codebase, featuring custom modules for creative portfolios, image galleries, cinematic video showcases, multi-author blogs, service descriptions, and company profile landing pages.

The template relies on a modern Astro and Preact foundation to balance rich visual interactivity with lightweight static output. Its aesthetic design centers around a dark visual layout, tailored for showcasing high-resolution art, photography, video production, and agency work. Blacks includes automatic search engine optimization (SEO) automation across all page types, ensuring metadata, open graph tags, and document structures are configured out of the box.

```text
Blacks Multipurpose System
├── Dark Landing & Company Profile
├── Image & Cinematic Video Gallery Systems
├── Content Blog & Article Pages
└── Promotion Widgets & Service Modules
```

Priced at $65 as a one-time purchase, [Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing](/themes/astro/blacks-complete-astro-themes/) offers 100% source ownership. It comes equipped with structured page indices, pre-built contact modules, specialized promotion widgets, and defined updating paths for about, service, and media pages. The theme eliminates the need to integrate separate plugins for portfolios, video displays, or blogs, unifying these requirements under one cohesive project tree.

## Features Comparison

### 1. Underlying Framework & Core Architecture

Docuna is built explicitly on top of Astro and Starlight. Starlight acts as an abstraction layer over Astro's core routing and content collection engine, providing built-in features necessary for technical documentation—such as frontmatter parsing, auto-generated table of contents, MDX support for custom components, and internationalization primitives. Docuna's architectural focus is maintainability of text-heavy documents, code examples, and technical step-by-step guides.

Blacks operates as a broad Astro multipurpose template using Preact for dynamic UI components where necessary. Instead of relying on a specialized sub-framework like Starlight, Blacks uses custom Astro page layouts, component structures, and content collections to drive its portfolio, gallery, blog, and service modules. This gives Blacks a broader layout footprint suited for visual design, while Docuna remains strictly optimized for documentation-first site architecture.

### 2. Content Structure and Authoring Model

Authoring content in Docuna revolves around MDX files placed inside the docs content directory. Technical writers can use standard Markdown formatting along with custom inline components to output code blocks, implementation examples, warning callouts, and multi-step installation guides. Sidebar structures can be manually defined or set to auto-generate based on file directory trees, reducing manual maintenance when expanding technical documentation sets.

Blacks handles content through distinct sub-systems tailored to specific content media types. It provides structured templates for blog articles, image gallery items, cinematic video showcases, and detailed service descriptions. Adding content to Blacks involves updating specific content collections or page-level files following the template's guidelines. It includes built-in guidance regarding critical system files that should remain untouched to preserve site routing and theme integrity.

### 3. Navigation, UI Layout, and Theme Modes

Navigation in Docuna follows classic technical documentation patterns. It includes a top header bar with a global search input (accessible via `Ctrl+K` keyboard shortcuts), theme toggle controls (Dark, Light, and System Auto settings), external repository links (such as GitHub), and a persistent collapsible sidebar for navigating multi-level documentation categories. The theme also includes a dedicated, clean landing page layout designed to transition users from top-level marketing copy directly into deep technical guides.

```text
Docuna Navigation Pattern:
[Logo / Title] -------- [Search (Ctrl+K)] [Theme Toggle (Dark/Light)] [GitHub Link]
[Sidebar Nav]  |  [Main MDX Documentation / Table of Contents]

Blacks Navigation Pattern:
[Navigation Bar: Home | About | Services | Gallery | Blog | Docs | Contact]
[Dark Cinematic Hero / Promotion Widgets / Video & Image Grid Modules]
```

Blacks utilizes a multipurpose header navigation bar featuring links to primary site sections: Home, About, Services, Gallery, Blog, Docs, and Contact. The UI is built entirely around a dark design aesthetic optimized for visual contrast, high-impact photography, and cinematic media. Rather than providing a light/dark mode switch, Blacks commits fully to a dark visual presentation, ensuring visual consistency across portfolios, galleries, and promotional landing sections.

### 4. Media Handling and Visual Assets

Docuna approaches media from a functional documentation perspective. Visual assets are primarily inline screenshots, architecture diagrams, code block syntax highlighting, and technical schematics standard within software documentation. The layout ensures text legibility, clear typography hierarchies, and structured table layouts for API endpoints or configuration options.

In contrast, visual media management is a primary feature of Blacks. It includes dedicated image gallery index layouts and specialized cinematic video gallery components designed to present high-resolution media efficiently. The responsive layout scales video embeds and photography grids across desktop and mobile devices without breaking design alignment, making it suitable for media producers and visual artists.

### 5. Search Engine Optimization (SEO) & Performance

Both templates leverage Astro's static build capabilities to output plain HTML files, ensuring fast loading speed and clean asset delivery. Fast loading performance directly enhances core web vitals and overall search engine visibility for both themes.

Docuna provides standard SEO controls via Starlight metadata configuration, allowing page-level meta tags, canonical URLs, and structured headings to be generated automatically from MDX frontmatter. Blacks features built-in automated SEO handling (`SEO auto`) tailored for multipurpose commercial sites. It automatically populates meta tags, social sharing cards (Open Graph), and page titles across blog posts, portfolio items, gallery pages, and service offerings without requiring manual meta tag construction for every page.

### 6. Configuration, Maintenance, and Promotion Tools

Configuring Docuna primarily involves editing the site's main configuration file to update the site title, domain, sidebar hierarchy, search behavior, and navigation links. Updating the landing page involves editing dedicated Astro components to alter hero sections, value proposition cards, and call-to-action buttons.

Blacks includes a wider variety of specialized configuration areas due to its multipurpose scope. The workflow includes instructions for updating global settings (site title, primary navigation, social links, contact forms) alongside specific page content (About, Services, Article Blog, and Gallery Index). Additionally, Blacks features built-in promotion widgets that allow site operators to showcase featured products, hire-us banners, or call-to-action cards directly across portfolio pages and blog articles.

## Pricing

When choosing a template, licensing model and total cost of ownership are key factors. Both Docuna and Blacks are sold under a transparent, one-time purchase agreement that grants 100% source code ownership without recurring subscription charges or hidden usage fees.

| Feature / Metric | Docuna - Astro Starlight Docs Template | Blacks - Astro Multipurpose Template |
| :--- | :--- | :--- |
| **Price** | $35 (One-time) | $65 (One-time) |
| **Source Ownership** | 100% Source Included | 100% Source Included |
| **Primary Focus** | Technical Documentation & Docs Landing | Portfolio, Gallery, Blog & Agency Multipurpose |
| **Base Engine** | Astro + Starlight | Astro + Preact |
| **Theme Modes** | Dark, Light, System Auto | Dedicated Dark Mode |
| **Built-in Search** | Yes (`Ctrl+K` Keyboard Search) | Page/Section Structured Navigation |
| **Media Galleries** | Inline Images / Diagrams | Image & Cinematic Video Systems |
| **SEO Handling** | Starlight MDX SEO Ready | Built-in Auto SEO Configuration |
| **Promotion Widgets** | Standard Landing CTA Sections | Custom Promotion & Hire-Us Modules |

At $35, [Docuna - Astro Starlight Docs Template - Documentation and Landing](/themes/astro/astro-documentation-starlight-docuna/) offers a cost-effective, specialized solution for developers needing a documentation hub with an integrated landing page. At $65, [Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing](/themes/astro/blacks-complete-astro-themes/) carries a higher price point reflecting its broader functional scope, extensive gallery components, blog framework, and multipurpose agency features.

## Who Should Choose Docuna - Astro Starlight Docs Template - Documentation and Landing

Docuna is structured for teams and individual developers whose primary objective is creating clean, accessible technical documentation. 

```text
Recommended Docuna Use Cases:
1. Open-Source Maintainers    --? Library & Framework Documentation
2. Developer Tool Creators   --? API References & Quickstart Guides
3. SaaS Engineering Teams    --? Technical Knowledge Bases & Release Notes
4. Hardware/SDK Developers   --? Implementation Guides & Code Tutorials
```

Specific user profiles that will benefit most from Docuna include:

*   **Open-Source Maintainers:** Software engineers launching open-source libraries, frameworks, or CLI utilities who need an out-of-the-box documentation site featuring code highlighting, version control clarity, keyboard search, and standard landing copy.
*   **Developer Tool & API Vendors:** Companies building developer-facing software products, SDKs, or APIs that require a unified portal containing both a high-converting landing page and deep, multi-level technical guides.
*   **SaaS Engineering Teams:** Technical teams building internal knowledge bases or external customer help centers where MDX content authoring, dark/light accessibility modes, and fast client-side searching are mandatory requirements.
*   **Technical Writers and Educators:** Content creators publishing structured tutorials, technical books, or code implementation guides who prefer Markdown-driven workflows over complex content management systems.

If your content structure relies heavily on text, hierarchical categories, code snippets, and fast reference searching, [Docuna](/themes/astro/astro-documentation-starlight-docuna/) is the logical choice.

## Who Should Choose Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing

Blacks is designed for users who need a high-impact, dark-themed visual website capable of presenting creative work, multimedia assets, and commercial services under one domain.

```text
Recommended Blacks Use Cases:
1. Digital Photographers & Filmmakers --? High-Res & Video Gallery Portfolios
2. Creative Agencies & Studios        --? Service Pages & Client Portfolios
3. Content Creators & Bloggers       --? Integrated Publishing & Promotion
4. Multidisciplinary Freelancers      --? Complete Professional Showcases
```

Specific user profiles that will benefit most from Blacks include:

*   **Digital Photographers and Videographers:** Visual artists requiring dedicated, high-performance image galleries and cinematic video layouts optimized for high-resolution displays within a dark theme.
*   **Creative Agencies and Design Studios:** Production houses, web design agencies, and digital studios seeking a dark agency portal to showcase portfolio items, describe service offerings, feature client case studies, and convert visitors via embedded promotion widgets.
*   **Multidisciplinary Freelancers and Consultants:** Independent professionals who need a single website that combines a personal portfolio, a technical or creative blog, a list of services, and a contact collection system without maintaining multiple templates.
*   **Content Creators and Publication Writers:** Digital publishers who require an integrated blogging system alongside creative showcases, featuring automated SEO management to maximize organic search indexing across published media.

If your primary focus centers on visual presentation, media galleries, agency branding, and multi-format content marketing, [Blacks](/themes/astro/blacks-complete-astro-themes/) offers the necessary capabilities.

## Verdict

Both Docuna and Blacks are robust templates built on the fast Astro static site framework, offering full source code ownership and zero subscription costs. However, their core capabilities serve fundamentally different use cases.

[Docuna - Astro Starlight Docs Template - Documentation and Landing](/themes/astro/astro-documentation-starlight-docuna/) excels at content organization for technical documentation. By leveraging Astro and Starlight, it solves the problem of structural navigation, code block presentation, theme switching, and instant search accessibility. It is purpose-built for software documentation, developer guides, and product landing pages where text legibility and fast information retrieval are critical.

[Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing](/themes/astro/blacks-complete-astro-themes/) succeeds as a broad, dark-themed multipurpose creative engine. It unifies portfolios, image galleries, cinematic video showcases, blog publishing, and agency landing pages into a cohesive package. Its built-in auto SEO, promotion widgets, and custom media layouts make it well-suited for visual creators, production studios, and businesses needing a bold digital footprint.

Your final decision comes down to your project's primary content medium:
*   Choose **Docuna** ($35) if your primary goal is organizing code, technical documentation, API references, and software installation steps within a clean, searchable docs layout.
*   Choose **Blacks** ($65) if your objective is establishing a dark-mode visual portfolio, media gallery, agency service showcase, and active blog within a single multipurpose environment.

Both templates eliminate the complexity of building custom site frameworks from scratch, allowing you to focus immediately on creating content and launching your site.

## See It Live

Experience the live functional demonstrations of each template directly in your browser:

*   Demo A: [Docuna - Astro Starlight Docs Template - Documentation and Landing](https://docuna.pages.dev/)
*   Demo B: [Blacks - Astro Multipurpose Template - Portfolio, Gallery, Blog, Landing](https://astro-blacks-themes.pages.dev/)

## Related Themes

Discover additional static site templates, landing page designs, and technical documentation themes across our complete directory:

*   Browse our full collection at [All Themes](https://www.hockeycomputindo.com/themes/).
*   Explore top-tier production templates at [Premium Themes](https://www.hockeycomputindo.com/premium/).