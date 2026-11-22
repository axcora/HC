---
layout: blog-detil.cax
title: PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order vs Docuna - Astro Starlight Docs Template - Documentation and Landing: Pricing, Performance & Verdict
description: Detailed technical comparison between PaperHouse bento portfolio template and Docuna Starlight documentation template for Astro site builders.
image: astro/astro-themes-paperhouse1_bdapzv.jpg
date: 2026-10-31
tags:
  - astro
  - astro template
  - bento portfolio
  - documentation template
  - starlight
  - tailwind
  - portfolio template
  - docs template
---

## Introduction

Selecting the ideal foundation for a web project requires evaluating your primary communication goals. The modern web developer ecosystem heavily favors static site generators and hybrid rendering engines that minimize client-side JavaScript, boost core web vitals, and streamline deployment pipelines. Within the Astro ecosystem, templates are often optimized either for narrative brand presence and service delivery or for dense technical information architecture.

The choice between a portfolio-first template and a documentation-first template comes down to structural priorities. Portfolio templates prioritize visual hierarchy, client acquisition, multi-format media displays, and service offerings. On the other hand, documentation templates focus on content organization, structural hierarchy, code block readability, quick search indexing, and rapid navigation across hundreds of technical topics.

This article provides an in-depth comparison between two specialized Astro templates: **PaperHouse**, a bento portfolio template engineered for creators and digital studios, and **Docuna**, an Astro Starlight documentation template tailored for technical documentation and product landing pages. We will compare their underlying technologies, architectural approaches, content management capabilities, styling frameworks, setup requirements, and total cost of ownership to help you decide which solution matches your build requirements.

## Overview of PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order

PaperHouse is a premium web starter template built on Astro 7 and Tailwind 4. Designed around a "slow web" design philosophy, it features a visual aesthetic suited for independent creators, digital craftspeople, creative directors, and boutique agencies. PaperHouse solves the problem of fragmented digital identities by consolidating a project portfolio, long-form blog, documentation area, and client order page into a single codebase.

Instead of requiring separate tools for your portfolio, knowledge base, and client onboarding, PaperHouse structures all these content types using Astro Content Collections driven by Markdown and JSON files. This approach eliminates hardcoded template text, allowing developers and designers to modify content directly inside text files without touching component code. You can learn more about its specific file organization and installation steps on the official [PaperHouse template page](/themes/astro/paperhouse-astro-themes/).

PaperHouse relies on modern styling techniques using Tailwind 4, utilizing bento grid components that adapt flexibly across mobile, tablet, and desktop viewports. The template includes integrated hero sections with dynamic marquees, customized work detail pages, structured journal entries, a built-in doc system, and a dedicated service order interface. It provides a complete client acquisition framework while retaining high performance through Astro's static site generation engine.

## Overview of Docuna - Astro Starlight Docs Template - Documentation and Landing

Docuna is a documentation template built on top of Astro and the Astro Starlight framework. Designed specifically for software products, developer tools, open-source libraries, and technical product manuals, Docuna combines a dedicated marketing landing page with a documentation engine. It allows teams to present a consumer-facing product overview on the root URL while serving technical user guides, API references, and release notes under a structured subpath.

The core strength of Docuna lies in its integration with Astro Starlight, a dedicated documentation framework. Out of the box, Docuna provides zero-configuration full-text search accessible via keyboard shortcuts (Ctrl+K), an automatically generated sidebar navigation system, dark and light theme toggling, and native support for MDX files. You can explore its full code configuration and sidebar features on the official [Docuna template page](/themes/astro/astro-documentation-starlight-docuna/).

Docuna focuses on code readability, low page load latencies, and structured technical writing. By building on Starlight's static architecture, it delivers pages with minimal JavaScript overhead. Developers own 100% of the source code upon purchase, allowing complete control over custom components, extra landing page sections, custom domain configurations, and localized documentation routes without third-party platform lock-in.

## Features Comparison

### Core Architecture and Engine Dependencies

PaperHouse runs on Astro 7 combined with Tailwind 4. Astro 7 provides modern component rendering capabilities, content layer optimizations, and refined asset handling pipelines. PaperHouse relies on Tailwind 4 for utility-first styling, enabling fine-grained controls over typography, layout grids, spacing primitives, custom colors, border radii, and visual textures such as grain and subtle shadows.

Docuna builds upon the Astro Starlight engine. Starlight acts as an integrated framework layer on top of Astro, introducing specific conventions for handling sidebar file routing, page metadata table-of-contents generation, dark mode state management, and code block syntax highlighting. Docuna extends Starlight by adding a custom landing page layout that integrates with the underlying documentation layout, providing a clean transition between marketing copy and technical guides.

### Layout System: Bento Grid vs. Technical Documentation Layout

PaperHouse uses a bento grid design paradigm across its homepage and index screens. Bento grids divide the layout into modular, asymmetrical content blocks that draw visual focus to featured projects, client metrics, platform highlights, and dynamic text marquees. This layout style is effective for showcasing varied content types side-by-side, such as a recent client work card right next to a featured blog post or service pricing block.

Docuna uses a technical documentation layout. Its landing page offers a hero section, feature feature grids, and call-to-action blocks. Once visitors navigate into the documentation area, Docuna transitions into a three-column layout: an expandable sidebar navigation tree on the left, the primary content view in the center with syntax-highlighted code blocks, and an auto-generated table of contents on the right for quick section jumping.

### Content Data Sources: Markdown, JSON, and MDX Support

Content management in PaperHouse is entirely content-driven through Astro Content Collections using plain Markdown (`.md`) and JSON files. Project data, blog posts, static page definitions, and documentation items are stored inside structured repository folders. For instance, creating a new work item or journal entry involves adding a Markdown file with defined frontmatter fields (such as title, date, client name, featured image, and tags). JSON data structures manage site configuration settings, typography defaults, and pricing options.

Docuna relies on MDX (`.mdx`) alongside standard Markdown inside Starlight’s standard content layout. MDX allows technical writers to embed interactive UI components, dynamic code previews, alerts, and custom tab containers directly inside technical articles. Starlight automatically reads the directory structure of the documentation folder to build routing trees and sidebar navigation arrays, requiring minimal manual updating when new markdown files are added to the codebase.

### Navigation, Search, and Interactive Elements

PaperHouse features interactive elements tuned for aesthetic portfolio presentation. The homepage includes a smooth continuous text marquee, interactive bento cards with hover states, smooth page transitions, and structured main navigation menus connecting the About, Docs, Works, Journal, and Contact/Order views. Search in PaperHouse is typically handled via static page listings or basic filter tags rather than an indexed full-text modal search engine.

Docuna focuses on quick navigation and instant access to technical information. It features a built-in search bar mapped to `Ctrl + K` or `Cmd + K`, allowing users to quickly search the entire documentation catalog. Furthermore, Docuna includes an automated theme switcher supporting Dark Mode, Light Mode, and System Default (Auto) modes, ensuring optimal code block contrast regardless of user operating system preferences.

### Conversion and Business Workflows: Order Pages vs. Knowledge Base Delivery

PaperHouse includes dedicated pages designed for client acquisition and commerce. It comes with a custom Order / Contact page template specifically structured for service inquiries, project scope definitions, and client intake forms. Combined with its Works portfolio layout and clear pricing card blocks, PaperHouse functions as an all-in-one sales portal for agencies, independent consultants, and design studios.

Docuna is structured primarily for developer education, product onboarding, and knowledge retention. While its landing page includes call-to-action buttons for downloading packages or navigating to a repository, it lacks a dedicated service order page or client proposal layout out of the box. Its target workflow focuses on reducing customer support queries by providing easy-to-read guides, API reference docs, and step-by-step setup tutorials.

### Customization, Rebranding, and Setup Requirements

Rebranding PaperHouse involves modifying Tailwind 4 configuration variables, JSON configuration files, and Astro page modules. Developers can update site-wide typography, accent colors, border radii, and visual grain filters from localized style configurations. Since all components are exposed directly inside the Astro source folder, developers have full access to modify HTML structures and CSS properties.

Docuna customization follows Starlight plugin and theme override conventions. Developers can modify the landing page layout using standard Astro components while adjusting the documentation layout through Starlight parameters in `astro.config.mjs`. Sidebar routes can be left on auto-generation mode or configured manually in code to lock down specific article sequences. Updating the documentation visual identity involves overriding Starlight's global CSS custom properties for light and dark color palettes.

## Pricing

| Feature / Metric | PaperHouse | Docuna |
| :--- | :--- | :--- |
| **Price (One-Time)** | **$45** | **$35** |
| **Primary Focus** | Bento Portfolio, Works, Blog, Docs, Order | Technical Docs, Product Manuals, Landing Page |
| **Framework Base** | Astro 7 + Tailwind 4 | Astro + Starlight |
| **Layout Paradigm** | Asymmetrical Bento Grid & Soft Studio Aesthetic | Marketing Landing Page + 3-Column Docs Layout |
| **Search Functionality** | Category & Tag Based Navigation | Built-in Full-Text Modal Search (`Ctrl + K`) |
| **Dark Mode Support** | Custom Styled Theme Engine | Integrated Light / Dark / Auto Theme Switcher |
| **Content Formats** | Markdown (`.md`) & JSON Configuration | Markdown (`.md`) & MDX (`.mdx`) |
| **Commerce / Intake** | Includes Built-in Order & Contact Template Page | CTA-focused Landing Page (No Order Form Template) |
| **Source Ownership** | 100% Full Source Code Included | 100% Full Source Code Included |

PaperHouse costs $45 as a one-time purchase. This price includes the full multi-page bento portfolio framework, work showcases, blog platform, order page template, documentation structure, and Tailwind 4 configuration files. There are no recurring subscription fees, and developers receive full ownership of the source code.

Docuna costs $35 as a one-time purchase. This lower price point reflects its focused scope on technical documentation, landing page presentation, and Starlight framework integration. Purchasing Docuna provides complete access to the project source code, including custom Starlight configurations, landing page components, and MDX setup files with zero recurring licensing costs.

## Who Should Choose PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order

PaperHouse is the ideal choice for professionals and organizations that need a complete web presence built around client acquisition, service delivery, and creative work showcase.

- **Boutique Design & Development Studios**: Studios requiring a polished visual site to display client case studies, detail service packages, run an active industry blog, and process project inquiries through a built-in order workflow.
- **Freelance Creative Engineers**: Developers and designers who want to showcase complex projects via modern bento grid layouts while retaining the ability to document technical work or publish software guides using an integrated docs section.
- **Digital Product Creators**: Individuals selling digital goods, templates, or consulting packages who need a clean aesthetic, strong visual hierarchy, zero client-side performance bottlenecks, and dedicated product ordering screens.
- **Developers Preferring Tailwind 4**: Tech leads and front-end engineers who prefer utility-first styling with the latest Tailwind 4 updates and modern Astro 7 architecture over standardized documentation layouts.

## Who Should Choose Docuna - Astro Starlight Docs Template - Documentation and Landing

Docuna is designed specifically for technical teams and software creators who prioritize documentation clarity, code searchability, and structured knowledge delivery.

- **Open-Source Maintainers**: Developers launching open-source packages, libraries, or frameworks who need a professional homepage paired with comprehensive technical documentation and automated sidebar generation.
- **SaaS & Developer Tool Teams**: Software-as-a-Service startups that require a landing page to present features and value propositions alongside a developer documentation portal for API specs and user guides.
- **Technical Writers & SDK Authors**: Content creators tasked with building accessible technical manuals who need built-in search (Ctrl+K), keyboard shortcuts, interactive MDX components, and dynamic dark mode options out of the box.
- **Teams Leveraging Astro Starlight**: Engineers who want the full power, reliability, and automated navigation capabilities of the Astro Starlight framework without spending time building a custom landing page from scratch.

## Verdict

Both PaperHouse and Docuna offer production-ready foundations built on Astro's fast static-site framework, but they serve fundamentally different primary requirements.

PaperHouse ($45) excels as a comprehensive visual identity engine and client acquisition platform. Its bento grid components, Tailwind 4 integration, soft studio styling, and built-in order intake workflow make it a strong solution for creators, agencies, and freelancers who want to present visual work, publish articles, document processes, and close client contracts within a single unified project repository.

Docuna ($35) stands out as a focused, highly accessible technical documentation framework. By building on top of Astro Starlight, it provides robust out-of-the-box features for documentation sites—such as global keyboard-driven search, light/dark mode toggling, automated sidebar trees, and MDX rendering—all paired with a polished landing page layout.

If your primary goal is to market services, showcase portfolio work, run a blog, and take client orders within an aesthetic bento layout, choose **PaperHouse**. If your primary goal is to publish software documentation, API guides, or technical product manuals with instant search and deep framework navigation, choose **Docuna**.

## See It Live

Demo A: [PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order](https://paperhouse-astro.pages.dev/)

Demo B: [Docuna - Astro Starlight Docs Template - Documentation and Landing](https://docuna.pages.dev/)

## Related Themes

Explore more static site themes and technical starters at [All Themes](https://www.hockeycomputindo.com/themes/) and inspect our curated collection of production-ready builds at [Premium Themes](https://www.hockeycomputindo.com/premium/).